# LAB: Parking Management System(YOLOv5)

## 1. Introduction

이번 프로젝트는 YOLO v5모델을 사용하여 실시간 카메라를 통해 입력되는 이미지만으로 차량을 인식한 결과를 바탕으로 차량 수를 자동으로 세서 현재 주차장에 남은 주차 가능 공간을 파악함으로써 주차장이용시 빠른 정보 제공을 통해 주차장을 효율적이고 편리하게 이용하도록 할 수 있는 주차장 관제시스템을 구현하였다.



![image-20210915163709444](https://user-images.githubusercontent.com/84532778/133397606-abfc74a9-ca09-4585-9f20-352a2a8e1f8c.png)



![image-20210915171234126](https://user-images.githubusercontent.com/84532778/133397673-669a9d9f-82e5-49c7-84d9-29fc56721a5a.png)



## 2. Procedure

### 2.1 Object Detection(Yolov5 model)

![image-20210915170509143](https://user-images.githubusercontent.com/84532778/133397734-85669f2a-8091-4e08-b059-3eaec06a3db3.png)

- **yolo v5의 모델별 성능비교.**

  ![image-20210915170805366](https://user-images.githubusercontent.com/84532778/133397780-33989302-7958-4baf-859d-e58bcd499643.png)

## 2.2 Parameter Setting

![image-20210915165619242](https://user-images.githubusercontent.com/84532778/133397813-f5e44784-3fbc-4bff-aaa9-b5b9c0e9b90d.png)

- **Car를 다른 class로 잘못 인식된 결과**

  - 주차장 관제 시스템이므로 목적에 맞게 'car' class에 대해서만 인식하도록 함.

- **하나의 객체가 중복으로 인식된 결과**

  - IOU threshold값과 confidence threshold 값 조절하여 결과 비교.

    ![image-20210915171148109](https://user-images.githubusercontent.com/84532778/133397863-0082da84-f5f0-4a81-ba28-9da4d5a4404b.png)
    
    

### 2.3 Counting Object

![image-20210915170716334](https://user-images.githubusercontent.com/84532778/133398024-f2312764-59fa-40d1-8531-4033abaf8d4b.png)

- 최종적으로 YOLOv5l 모델을 사용하였다.

- IOU threshold = 0.45, Confidence threshold = 0.33으로 설정.

  

## **3. Conclusion** 

이번 프로젝트에서는 주차장으로 사용되어질 수 있는 환경에서 주차 가능한 공간을 찾아주는 모델을 만들었다. 주어진 Counting reference 결과 비교와 모델들의 성능 평가를 기준으로 주어진 모델들 중 주차 시스템에 사용될 모델로 yolov5l 을 선택하였다. 

고려되어진 하이퍼 파라미터는 IOU와 Confidence, FPS 이다. 이 변수들의 default 값에 대하여 실험을 진행 한 결과 default 값 기준, IOU threshold 값의 변화로는 성능을 향상시킬 수 없었으며 Confidence threshold의 값을 올려 IOU threshold =0.45, Confidence threshold= 0.33 에서 100%의 정확도를 보여주는 것을 확인하였다. 

FPS 의 값이 6이므로 실제 적용되어 실시간으로 관측하기 위해서는 GPU의 성능이 더 좋은 것을 사용해야할 것이다.



## 4. Reference

[1]   [YOLOv5 - Introduction (tistory.com)](https://bigdata-analyst.tistory.com/194)

[2]   [ultralytics/yolov5: YOLOv5 in PyTorch > ONNX > CoreML > TFLite (github.com)](https://github.com/ultralytics/yolov5) 

[3]  https://bigdata-analyst.tistory.com/194

[4]  https://dyndy.tistory.com/275 

[5] [Tutorials of Object Detection using Deep Learning  How to measure performance of object detection (hoya012.github.io)](https://hoya012.github.io/blog/Tutorials-of-Object-Detection-Using-Deep-Learning-how-to-measure-performance-of-object-detection/)
