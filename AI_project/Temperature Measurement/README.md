# LAB: Parking Management System(YOLOv5)

## 1.Introduction

This project deals the image segmentation method which is used to detect and measure the 
maximum and average temperature of the mask-worn faces.

There are two parts for this lab: part 1 is to draw contour and rectangle on the area where temperature is to be measured, and the second part is to convert the color data into intensity value which is then converted into temperature magnitude. 

![image-20210916074723650](https://user-images.githubusercontent.com/84532778/133525877-b0169f6a-9db9-4b73-b93f-d55e67e994b1.png)



## 2. Procedure

**Part 1. Face Segmentation excluding mask.**

![image-20210916075700050](https://user-images.githubusercontent.com/84532778/133525898-c2d5bd08-fbd4-435f-a367-cf452f6e4872.png)

- The first step is to import the video and convert the color space from **RGB** to **HSV**.



![image-20210916080300169](https://user-images.githubusercontent.com/84532778/133525928-a99ca60b-d8b7-44e8-92c8-588728001130.png)

- The color edges are clearer when the Sobel filter is used.

- Using the **inRange()** function, the ranges of each **hue, saturation,** and **value** magnitudes are determined.



![image-20210916080751017](https://user-images.githubusercontent.com/84532778/133525949-c95d9c8a-080c-4de1-9977-e84ac26f4e3c.png)

- Morphology was used to make the extracted result from the previous step to be more apparent. 
- Different types of morphology can affect the image after thresholding. 



![image-20210916081021613](https://user-images.githubusercontent.com/84532778/133525964-d546d92b-9edd-4fa9-a565-08b5625196c8.png)

- Detecting contours of the connected objects.
- This was managed by using the contour size function.

-  Rectangular box outlines identifying the contours were drawn as well.



**Part 2. Temperature Measurement**

By using a simple equation below, the intensity was converted into temperature ranging from 25~40°*c*.

![image-20210916081815993](https://user-images.githubusercontent.com/84532778/133526064-c42c523f-8766-482c-80d2-58592865c636.png)

![image-20210916082153539](https://user-images.githubusercontent.com/84532778/133526095-b2b7cd8f-dc18-47a0-9248-d5e96136139d.png)

- The warning message must display if the average temperature exceeds 38°*c*.

- Only the top 3~5% of data was attained, removing all the room temperature intensity data.
- First 0.5% data was eliminated just in case of an unexpected hot element attained by the sensor.



## 3. Conclusion

This project mainly dealt with conversion of an IR image to HSV color space, thresholding each H,S, and V channel with specified minimum and maximum value of the interested region, and utilizing the intensity data in the value channel. The importance of selecting proper filter type and morphology method was once again emphasized. We learned new image processing techniques such as obtaining the contour and intensity data for the region of interest and sorting the data to process the given requirements. 
