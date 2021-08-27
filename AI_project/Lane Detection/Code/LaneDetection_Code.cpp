#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;



std::vector<std::string> block_string(std::string input, int want_block_length)
{
    std::vector<std::string> ret;
    int length;


    std::string str = input;

    while (str.length() > want_block_length)
    {
        std::string msg = str.substr(0, want_block_length);
        std::string rest = str.substr(want_block_length);

        // std::cout << msg << " " << rest << std::endl;
        ret.push_back(msg);

        str = rest;
    }

    // std::cout << str << std::endl;
    ret.push_back(str);

    return ret;
}

#define OUTPUT_VIDEO_NAME "Result_Lab2.avi" 

int main(int argc, char** argv)
{
    //변수 선언
    Mat image, src, src_gray, dst, cdst, dst_tresh, dst_morph, cdstP, aw_mask;

    // 비디오 load
    VideoCapture cap("Part1_lanechange1.mp4");
    VideoWriter videoWriter;
    if (!cap.isOpened())   // if not success, exit the programm
    {
        cout << "Cannot open the video cam\n";
        return -1;
    }
    int key = 0;
    double b, x0_L, y0_L, x3_L, y3_L, x0_R, y0_R, x3_R, y3_R, y3, x_b, y_b;
    x0_R = 0, y0_R = 0, x3_R = 0, y3_R = 0;
    double m_R = 0, m_L = 0, b_R = 0, b_L = 0;
    float bias_val = 0;

    //write video
    float videoFPS = cap.get(cv::CAP_PROP_FPS);
    int videoWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //650
    int videoHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //512
    videoWriter.open(OUTPUT_VIDEO_NAME, VideoWriter::fourcc('M', 'J', 'P', 'G'),
        videoFPS, Size(videoWidth, videoHeight), true);
    while (1)
    {
        // Check if image is loaded fine
        bool bSuccess = cap.read(image);
        Mat dst_track = Mat::zeros(image.size(), CV_8UC3);
        image.copyTo(src);
        if (!bSuccess)   // if not success, break loop
        {
            cout << "Cannot find a frame from  video stream\n";
            break;
        }
        key = waitKey(5);
        if (key == 27) // wait for 'ESC' press for 30ms. If 'ESC' is pressed, break loop
        {
            cout << "ESC key is pressed by user\n";
            break;
        }

        //이미지 GRAYSCALE 변환
        cvtColor(src, src_gray, COLOR_BGR2GRAY);



        // + Filter
        GaussianBlur(src_gray, src_gray, Size(3, 3), 2);

        // + threshold 
        threshold(src_gray, dst_tresh, 130, 255, 0); //binary type, 130 
        //imshow("dst_tresh", dst_tresh);

        // + Morphology
        Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
        morphologyEx(dst_tresh, dst_morph, MORPH_CLOSE, element);

        // Edge detection
        Canny(dst_morph, dst, 130, 255);

        //ROI 설정
        Mat poly_roi;
        Mat poly_mask = Mat::zeros(dst.size(), dst.type()); // ROI 영역만 표시하기위한 검정색 마스크 생성
        Point poly[1][4];

        int H = dst.rows;
        int W = dst.cols;

        poly[0][0] = Point(0, H - 50); //아래 왼쪽
        poly[0][1] = Point(W, H - 50); //아래 오른쪽
        poly[0][2] = Point(W, H / 2); // 위 오른쪽
        poly[0][3] = Point(0, H / 2); // 위 왼쪽
        const Point* ppt[1] = { poly[0] }; // 포인트 값들의 열 (모두 0열)
        int npt[] = { 4 }; // 가장자리의 수
        fillPoly(poly_mask, ppt, npt, 1, Scalar(255, 255, 255), 8);
        dst.copyTo(poly_roi, poly_mask);

        //Hough Transform
        vector<Vec4i> linesP;
        HoughLinesP(poly_roi, linesP, 1, CV_PI / 180, 20, 20, 40); // 최소교차수: 50, 최소길이: 60, 점사이 최대간격: 30
        cout << "line size: " << linesP.size() << endl;

        //Draw the lines
        y3 = H / 2;
        double count_r = 0;
        double count_l = 0;
        double count_b = 0;
        double FPS = 0;

        for (size_t i = 0; i < linesP.size(); i++)
        {
            Vec4i l = linesP[i]; 
            double y = l[3] - l[1];
            double x = l[2] - l[0];
            double m = y / x;
            b = l[3] - m * l[2];
            x_b = (H - b) / m;
            if (l[3] > (H / 2) && abs(m) > 0.55 && abs(m) < 1)
            {
                // Line Drawing
                if (m > 0 && count_r == 0) { //right lane
                    m_R = m;
                    b_R = b;
                    y0_R = H;
                    x0_R = (y0_R - b_R) / m_R;
                    x3_R = (b_L - b_R) / (m_R - m_L);
                    y3_R = m_R * x3_R + b_R;
                }
                if (m < 0 && count_r == 0) { //left lane
                    m_L = m;
                    b_L = b;
                    y0_L = H;
                    x0_L = (y0_L - b_L) / m_L;
                    x3_L = (b_R - b_L) / (m_L - m_R);
                    y3_L = m_L * x3_L + b_L;
                }
                if (abs(bias_val) < 25)
                {
                    if (m > 0 && y3_R != 0) {
                        line(src, Point(x0_R, y0_R), Point(x3_R, y3_R), Scalar(255, 0, 0), 3, LINE_AA);
                        circle(src, Point(x3_L, y3_L), 8, Scalar(0, 0, 255), -1);
                        count_r = 1;
                        //break;
                    }
                    if (m > 0 && y3_R != 0 && count_r == 0) {
                        line(src, Point(x0_R, y0_R), Point(x3_R, y3_R), Scalar(0, 255, 255), 3, LINE_AA);
                        circle(src, Point(x3_L, y3_L), 8, Scalar(0, 0, 255), -1);
                        count_r = 1;
                    }
                    if (m < 0 && y3_L != 0) {
                        line(src, Point(x0_L, y0_L), Point(x3_L, y3_L), Scalar(255, 0, 0), 3, LINE_AA);
                        circle(src, Point(x3_L, y3_L), 8, Scalar(0, 0, 255), -1);
                        count_l = 1;
                        //break;
                    }
                    if (m < 0 && y3_L != 0 && count_l == 0) {
                        line(src, Point(x0_L, y0_L), Point(x3_L, y3_L), Scalar(0, 255, 255), 3, LINE_AA);
                        circle(src, Point(x3_L, y3_L), 8, Scalar(0, 0, 255), -1);
                        count_l = 1;
                    }
                }
            }
            if (abs(bias_val) > 25 && (x_b < (W / 2) + 200) && (x_b > (W / 2) - 200))
            {
                if (bias_val < 0 && y3_R != 0 && count_b == 0) {
                    line(src, Point(x_b, H), Point(x3_R, y3_R), Scalar(0, 0, 255), 3, LINE_AA);
                    circle(src, Point(x3_R, y3_R), 8, Scalar(0, 0, 255), -1);
                    count_b = 1;
                    //break;
                }
            }

        }

        //FPS display
        string fps = to_string(cap.get(CAP_PROP_FPS));
        string fps_str = fps.substr(0, 4); 
        cv::putText(src, "FPS : " + fps_str, Point(100, H/2), CV_FONT_HERSHEY_SIMPLEX,1, Scalar(0,0,255),2);


        //Bias Calculation
        double center = W / 2;
        double bias_int = x3_L; 
        double bias_val_R = x0_R - bias_int;
        double bias_val_L = bias_int - x0_L;
        bias_val = floor(100.00*((bias_val_R - bias_val_L) / (x0_R - x0_L) * 100))/100.00;

        string bias;
        string bias_per;
        string bias_rate;

        if (bias_val > 0)
        {
            bias = "Bias : Left ";
            bias_per = to_string(abs(bias_val));
            bias_rate = bias_per.substr(0, 4);
            cv::putText(src, bias + bias_rate + "%", Point(W * 0.1, 50),
                CV_FONT_HERSHEY_SIMPLEX, 1, Scalar::all(0), 2);
        }
        else
        {
            bias = "Bias : Right ";
            bias_per = to_string(abs(bias_val));
            bias_rate = bias_per.substr(0,4);
            cv::putText(src, bias + bias_rate + "%", Point(W * 0.1, 50),
                CV_FONT_HERSHEY_SIMPLEX, 1, Scalar::all(0), 2);
            cout << bias + bias_per << endl;
        }

        if (abs(bias_val) > 25)
        {
            if (bias_val > 0)
            {
                cv::putText(src, "In Line? :Lane Changing", Point(W * 0.2, 100),
                    CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2);
                cv::putText(src, "<--", Point(W * 0.5, H * 0.25),
                    CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2);
            }
            else
            {
                cv::putText(src, "In Line? :Lane Changing", Point(W * 0.2, 100),
                    CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2);
                cv::putText(src, "-->", Point(W * 0.5, H * 0.25),
                    CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2);
            }
        }
        else
        {
            cv::putText(src, "In Line? :Safe", Point(W * 0.2, 150),
                CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 2);
        }

        line(src, Point(W / 2, H), Point(W / 2, H - 100), Scalar(255, 255, 255), 3, LINE_AA);


        // Addweight ROI
        Mat aw_roi;
        aw_mask = Mat::zeros(src.size(), src.type());
        Point aw[1][3];
        aw[0][0] = Point(x0_L, src.rows); //아래 왼쪽
        aw[0][1] = Point(x0_R, src.rows); //아래 오른쪽
        aw[0][2] = Point(x3_R, y3_R); // vanishing point
        const Point* awppt[1] = { aw[0] }; // 포인트 값들의 열 (모두 0열)
        int aw_npt[] = { 3 }; // 가장자리의 수

        if (abs(bias_val) < 25)
            fillPoly(aw_mask, awppt, aw_npt, 1, Scalar(0, 255, 0), 8);
        else
            fillPoly(aw_mask, awppt, aw_npt, 1, Scalar(0, 0, 255), 8);

        Mat src_aw;
        addWeighted(src, 1, aw_mask, 0.3, 0.0, src_aw);

        // Show results
        namedWindow("Result", WINDOW_FREERATIO);
        imshow("Result", src_aw);
        videoWriter << src_aw;
        // Wait and Exit
        //waitKey();
    }
    return 0;
}

