//#include "opencv2/video/tracking.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <ctype.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define OUTPUT_VIDEO_NAME "Result.avi" 

int main()
{
    Mat image, image_disp, hsv, dst, dst_filter, dst_morph, mul;
    vector<vector<Point> > contours;
    vector<Point2f>center(contours.size());
    vector<float>radius(contours.size());
    vector<Vec4i> hierarchy;
    VideoCapture cap("IR_DEMO_cut.AVI");
    VideoWriter videoWriter; 



    if (!cap.isOpened())   // if not success, exit the programm
    {
        cout << "Cannot open the video cam\n";
        return -1;
    }
    int key = 0;

    //write video
    float videoFPS = cap.get(cv::CAP_PROP_FPS);
    int videoWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //650
    int videoHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //512
    videoWriter.open(OUTPUT_VIDEO_NAME, VideoWriter::fourcc('M', 'J', 'P', 'G'),
    videoFPS, Size(videoWidth, videoHeight), true);
        
    while (1)
    {
        bool bSuccess = cap.read(image);
        Mat dst_track = Mat::zeros(image.size(), CV_8UC3);
        image.copyTo(image_disp);
        if (!bSuccess)   // if not success, break loop
        {
            cout << "Cannot find a frame from  video stream\n";
            break;
        }
        key = waitKey(30);
        if (key == 27) // wait for 'ESC' press for 30ms. If 'ESC' is pressed, break loop
        {
            cout << "ESC key is pressed by user\n";
            break;
        }

        for (;;)
        {
            cap.read(image);
            imshow("Source", image);
            Mat grad_x, grad_y,filtered;

            Sobel(image, grad_x, CV_8U, 1, 0);
            Sobel(image, grad_y, CV_8U, 0, 1);
            addWeighted(grad_x, 0.3, grad_y, 0.3, 0,filtered);
            
            image = image + filtered ;
            imshow("sobel", image); 
            //GaussianBlur(image, image, Size(3, 3), 3);
            //imshow("gaussian", image); 

            cvtColor(image, hsv, COLOR_BGR2HSV);  // HSV로 변환  
            image.copyTo(image_disp);

            //=========================== filtering====================================/
            //GaussianBlur(hsv, dst_filter, Size(3, 3), 1);
            //imshow("filter", dst_filter);
            //=========================================================================/

            //-------------------- set dst as the output of InRange---------------------/
            inRange(hsv, Scalar(0, 100, 150), Scalar(50, 255, 255), dst); // inRange를 통해 범위 제한
            //namedWindow("InRange", 0);
            imshow("InRange", dst);
            //--------------------------------------------------------------------------/

            //==============================morphology==================================/
            Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
            morphologyEx(dst, dst_morph, MORPH_CLOSE, element); // set dst_morph as the output of morphology
            imshow("dst_morph", dst_morph);
            //==========================================================================/


            ///  Find All Contour   ///
            findContours(dst_morph, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
            if (contours.size() > 17) // 최소 contour size를 17으로 하여 멀리있는 대상과 이마나 목이 아닌부위 제외
            {
                /// Find the Contour with the largest area ///
                int idx = 0, largestComp = 0;
                double maxArea = 0;
                for (; idx >= 0; idx = hierarchy[idx][0])
                {
                    const vector<Point>& c = contours[idx];
                    double area = fabs(contourArea(Mat(c)));
                    if (area > maxArea)
                    {
                        maxArea = area;
                        largestComp = idx;
                    }
                }
                // contour부분 bounding box 좌표
                Rect boxPoint = boundingRect(contours[largestComp]);

                ///  Draw the max Contour on Black-background  Image ///
                Mat dst_out = Mat::zeros(dst_morph.size(), CV_8UC3);
                drawContours(image_disp, contours, largestComp, Scalar(255, 255, 255), 2, 8, hierarchy);
                drawContours(dst_out, contours, largestComp, Scalar(255, 255, 255), -1, 8, hierarchy);
                namedWindow("Contour", 0);
                //imshow("Contour", dst_out);

                //only contour
                // contour 이미지를 0~1로 normalization하고 원본 이미지와 convolution해주어 contour에 해당하는 부분만 값을 가지게함
                mul = Mat::zeros(image.size(), CV_8UC3);
                mul = image.mul(dst_out / 255);
                //imshow("mul", mul);

                //SPLIT
                Mat mul_final, mul_split[3];
                split(mul, mul_split);
                Mat mul_v = mul_split[2]; //hsv중 contour에 해당하는 v값
                Mat mul_reshape = mul_v(boxPoint).clone().reshape(0, 1); // 2D -> 1D
                cv::sort(mul_reshape, mul_final, SORT_DESCENDING); //각 countour당 최대 v값 정렬


                int cut = (mul_final.cols) * 0.005; //전체 0.5%  데이터의 수 (소수점 버린값->주소값 때문에 정수)
                int T_max = trunc(25 + (double)mul_final.at<uchar>(0, 0) * 15 / (255)); // 최고온도
                double T_sum = 0;// 상위 0.5%를 제외한 후 상위 5%의 합
                int T_avg = 0;// 평균온도
                double T_v = 0; //countour 내 온도값
                int high = (mul_final.cols) * 0.05; //상위 5% 개수
                for (int i = 0; i < (high - cut); i++) //상위 0.5%를 제외한 후 상위 5%의 합
                {
                    T_v = (double)mul_final.at<uchar>(cut + i);
                    T_sum += 25 + (T_v * 15 / 255);
                }
                T_avg = trunc(T_sum / (high - cut)); //평균 온도
                //cout << "T_avg:" << T_avg << endl; //각 countour당 평균 온도

                //최고온도 출력
                string max = "Max:";
                string str1 = to_string(T_max);
                cv::putText(image_disp, max + str1, Point(image_disp.cols * 0.05, 50),
                    CV_FONT_HERSHEY_SIMPLEX, 0.8, Scalar::all(255), 2);

                //평균온도 출력
                string avg = "Avg:";
                string str2 = to_string(T_avg);
                cv::putText(image_disp, avg + str2, Point(image_disp.cols * 0.3, 50),
                    CV_FONT_HERSHEY_SIMPLEX, 0.8, Scalar::all(255), 2);

                if (T_avg >= 38) //38 이상의 온도일 때 Warning 출력
                {
                    cv::putText(image_disp, "WARNING", Point(image_disp.cols * 0.05, 150),
                        CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2);
                }

                /// Draw the Contour Box on Original Image ///
                rectangle(image_disp, boxPoint, Scalar(255, 0, 255), 3);// contour에서 박스 그리기
                namedWindow("Contour_Box", 0);
                imshow("Contour_Box", image_disp);
                videoWriter << image_disp;

                ///// Continue Drawing the Contour Box  ///
                rectangle(dst_track, boxPoint, Scalar(255, 0, 255), 3);// contour box가 누적되어 검은 화면에 그려짐
                //namedWindow("Contour_Track", 0);
                //imshow("Contour_Track", dst_track);
            }
            else
            {
                ///  Draw the max Contour on Black-background  Image ///
                Mat dst_out = Mat::zeros(dst_morph.size(), CV_8UC3);
                //namedWindow("Contour", 0);
                //imshow("Contour", dst_out);

                //only contour
                mul = Mat::zeros(image.size(), CV_8UC3);
                mul = image_disp.mul(dst_out / 255); // 원본 이미지에 contour 이미지를 normalization하여서 행렬곱을 해주어 contour에 해당하는 이미지만 출력
                //imshow("mul", mul);

                /// Draw the Contour Box on Original Image ///
                namedWindow("Contour_Box", 0);
                imshow("Contour_Box", image_disp);
                videoWriter << image_disp;
                ///// Continue Drawing the Contour Box  ///
                //namedWindow("Contour_Track", 0);
                //imshow("Contour_Track", dst_track);
            }

            char c = (char)waitKey(10);
            if (c == 27)
                break;
        } // end of for(;;)

    }
    return 0;
}