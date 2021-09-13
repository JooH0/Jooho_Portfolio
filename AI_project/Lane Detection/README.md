# LAB_Simple Lane Detection with OpenCV

## **1. Introduction**

This project mainly deals with straight lane detection and departure warning.

The ultimate goal is to effectively detect any valid lanes, and any other line components outside the road must be eliminated or neglected. Additionally, if the vehicle is departing from the course, the program must identify whether or not the vehicle is undergoing lane departure, by showing a warning message.

![image-20210913151007802](https://user-images.githubusercontent.com/84532778/133054441-77586ec3-5d15-4ad4-be20-f5bbcd6a9164.png)



## **2. Procedure**

**2.1 Preprocessing**

![image-20210913174632236](https://user-images.githubusercontent.com/84532778/133054611-412ebef3-0010-43b2-b797-193a3584c2b3.png)

- loading the video in Grayscale

- Gaussian Blur Filter

- Thresholding and Morphology

  

**2.2 Canny edge detection**

![image-20210913174706756](https://user-images.githubusercontent.com/84532778/133054679-e2565ece-1cef-4697-bdf5-7361a871654c.png)

- Set ROI(The Region of interest)

-  Canny edge detection

  

**2.3 Lane detection using Hough transformation.**

![image-20210913174748293](https://user-images.githubusercontent.com/84532778/133054728-eec2c64e-4d7c-4e4a-94fa-03fbb1a8f93c.png)

- Use Hough LineP() function in OpenCV

- Hough line detection

  

**2.4 Line drawing algorithm**

- Negative slope indicates that right lane and positive slope indicates the left lane. 

- Valid lines were identified by setting the ranges for the magnitude of slope value.

- The vanishing point is identified by calculating the interception point of two crossing lines from the simple slope equation 𝑦 = 𝑚𝑥 + 𝑏.

-  The conditional statement makes the program to draw only one line per frame.

  

**2.5 Departure calculation**

<img src="https://user-images.githubusercontent.com/84532778/133054874-9308fa94-5034-45c0-9073-33ee2ae5b0c5.png" alt="image-20210913174858136" style="zoom:67%;" />



![image-20210913174809476](https://user-images.githubusercontent.com/84532778/133054806-9da27141-8f74-4650-a24a-d534201df426.png)

![image-20210913174924695](https://user-images.githubusercontent.com/84532778/133054927-773ee2f7-c887-4de8-8b81-5ca83fbc0c00.png)

- The departure rate is shown in the original video, and the lane changing condition is determined if the departure rate exceeds 25%.



## **3. Conclusion** 

In this lab, various image processing methods were applied to detect lane in a vehicle-driving video. What made this lab quite intriguing is that such procedures are actively used in autonomous driving system, since accurate lane detection is inevitable for safe driving condition. Same preprocesses were taken place similar to the previous tutorial and lab. In addition to the image processing methods, FPS, frames per second was displayed in order to check whether or not the lane detecting program is adequate enough for other type of videos. This is because 30 FPS is mostly used in lane detection. Although the program we made might not work in other road conditions, learning the basic algorithm of lane detection using Canny edge detection and Hough transform were the main purposes of this lab.

