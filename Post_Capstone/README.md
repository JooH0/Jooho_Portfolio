# post_capstone

### **1. DeepRacer_Tutorial**

   이 프로젝트는 AWS에서 제공하는 강화학습 플랫폼을 사용하여 약 18개의 환경변수들을 통해서 Reward function을 다르게 정의하여 PPO, SAC 등의 알고리즘을 학습에 적용시켜 직접 모델을 훈련하여 정해진 트랙을 벗어나지 않고 안정적으로 주행하는 수준으로 학습시키는 것을 목표로한다.

- AWS에서 제공하는 플랫폼에서 학습한 모델은 AWS DeepRacer 하드웨어에만 적용 가능하며 다양한 환경에 대해서 customize하기가 어렵다.

- Reference: [AWS Deepracer_How to train a model in 15 minutes](https://falktan.medium.com/aws-deepracer-how-to-train-a-model-in-15-minutes-a07ab77fb793)

   

### **2. UNITY 3D_Tutorial**

   이 프로젝트는 3D 및 2D 비디오 게임의 개발 환경을 제공하는 게임 엔진인Unity를 사용한다. 실제 환경과 유사한 가상환경을 구현하고 강화학습 라이브러리인 ML-agents를 사용하여 PPO 알고리즘 기반의 학습을 진행한다. 최종적으로 카메라로 들어오는 이미지를 인지하며 자율주행 가능한 모델을 만드는 것을 목표로한다.

- Unity3D 환경에서는 직접 가상환경을 제작할 수 있으며 여러 센서들을 사용하여 다양한 학습환경을구현할 수 있다.

- Agent는 매 step마다 Input image에 대해 action을 선택하며 한 시나리오동안 보상이 가장 높아지는 판단을 기억하며 점차 나은 모델로 발전한다.

- Unity 환경에서 학습된 모델을 실제 환경인 LattePanda와 Arduino를 포함하는 임베디드 시스템에 적용시켜본다.



### **3. Presentation Video**
[![image](https://user-images.githubusercontent.com/84532778/131083934-07e389cd-2d5c-41dd-a02b-531bce2d9967.png)](https://www.youtube.com/watch?v=10BTBinHHnM)

- Link: [Demo video](https://www.youtube.com/watch?v=10BTBinHHnM)

   

