# License Plate Recognition(YOLOv3, OCR)

## **1. Introduction**

이번 프로젝트에서는 Object detection 모델인  YOLOv3를 사용하여 차량번호판을 인식하고 파이썬 기반의 OCR 프로그램인 Py-tesseract를 통해 차량번호판의 정보들을 인식하는 모델을 만든다.

심화 목표로는 Object Recognition을 실제에서 사용될 수 있는 Business 모델로 학교로 들어오는 버스를 인식하고 버스의 차량번호판을 실시간으로 인식하여 해당 시간대에 출입한 버스에 대한 정보를 제공하여서 코로나 상황에서의 확진자 동선과 본인의 동선을 확인할 수 있도록 하는 단계까지 구현하는 것이다. 



![image-20210915015958482](https://user-images.githubusercontent.com/84532778/133398084-089da3b2-b779-4631-8a7b-942ca90a1290.png)



## **2. Procedure**

### 2.1 Object Detection(YOLOv3)

![image-20210915023002501](https://user-images.githubusercontent.com/84532778/133398167-bba71ce0-0440-4d34-ac68-3d4826333a42.png)

![image-20210915023031933](https://user-images.githubusercontent.com/84532778/133398233-0f6a97b6-f476-4849-ae2c-0615f5f9e9b7.png)

- License plate detection model
- Crop the detected Images

### **2.1 Preprocessing**

![image-20210915023122863](https://user-images.githubusercontent.com/84532778/133398276-1e05383f-8bcb-49a6-9291-463d22d8aaa3.png)

1. Grayscale

2. TopHat, BlackHat

3. Thresholding, GaussianBlur

4. Find contours

5. 사각형 형태의 multiple box 그리기

6. 최소 사각형 크기를 제한하여 문자가 존재할 만한 사각형만을 추려냄

   

### **2.3 OCR (Py-tesseract)**

![image-20210915025301284](https://user-images.githubusercontent.com/84532778/133398316-71d60592-a0b5-4989-9037-ebaf81e9e5d0.png)

- Single text line (일반적인 차량 번호판 Text 형태)

  

![image-20210915035709104](https://user-images.githubusercontent.com/84532778/133398369-c932b0b4-cc15-43f4-985a-42dd92a387c9.png)

- 한글의 첨자 부분의 인식률이 낮게 나타남

- 한글은 3byte, 숫자는 1byte로 보통 single line text 차량번호판일 경우 

  ’00한0000’ or ‘000글0000’ 형식이므로 9, 10 byte로 크기 제한

- 글자수에 대한 조건으로 보통 single line 차량 번호판일 경우 

  ’00한0000’ or ‘000글0000’ 형식이므로 7~8개로 이루어진 결과만을 출력하도록 제한

## **3. Conclusion** 

![image-20210915030632987](https://user-images.githubusercontent.com/84532778/133398415-8e69b750-adc8-42e6-8618-d048ec25f9e4.png)



![image-20210915031710617](https://user-images.githubusercontent.com/84532778/133398450-daf8e0df-57f9-4a79-aac8-955311f87c2d.png)

이번 프로젝트를 진행하면서 LPR을 수행하는데 주로 사용되었던 YOLO와 OCR의 원리에 대해서 자세
히 알아볼 수 있는 시간이었다. YOLO의 원리인 Grid 생성을 통한 Single convolutional network 구조
로 이전까지 사용되었던 R-CNN보다 훨씬 빨리 물체를 인식하는 것을 알게 되었다. 또한 OCR을 수행
하는데 있어서 원본 이미지를 바로 사용하지 않고 이미지 전처리 과정들을 먼저 수행하는 것을 통해
OCR이 원활하게 이루어지도록 하는 원리에 대해서 알게 되었다. 
