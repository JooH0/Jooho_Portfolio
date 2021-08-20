# AWS DeepRacer Tutorial (2021. 06. ver.)

---

## 1. Enter AWS website to prepare for DeepRacer training.

https://console.aws.amazon.com/deepracer/home?region=us-east-1#welcome

**1. You can see the AWS DeepRacer homepage through the link above.**

![AWS1](https://user-images.githubusercontent.com/84532778/130181439-60155ace-bd4b-4193-94e1-35f66ae7dd3b.png)



**2. Click on the banner on the left side of the window.**

![AWS2](https://user-images.githubusercontent.com/84532778/130181442-dc9a6026-7e68-44cc-95b8-f75968115d10.png)



**3. You can see several menus for reinforcement Learning.**

![AWS3](https://user-images.githubusercontent.com/84532778/130181443-ec35d252-9dfc-4ba3-bf39-e456ade34e01.png)

---

**Get started** : you can create model.

**Your models** : you can see the models you made before.

**Your garage** : you can configure your vehicle with one or more sensors, choose a neural 			            network topology, and customize the action space to meet your racing criteria.

---



## 2. Create your reinforcement learning model

**1. Click the "Get started" for creating your custom model**

![AWS4](https://user-images.githubusercontent.com/84532778/130181447-5304b422-02c1-4eed-bc6b-76a0fb3f57c1.png)

---

**start the course :** You can get basic reinforcement learning knowledge and general 							      information about DeepRacer (It takes about 10 minutes).

---



**2. Create your custom model** (Follow the steps provided by AWS)

Enter the name of your model.

![AWS5](https://user-images.githubusercontent.com/84532778/130181448-848b9d99-9425-475d-ae9a-92452e0f82c2.png)

---



**3. Choose a course you want to simulate.**

![AWS6](https://user-images.githubusercontent.com/84532778/130181451-4eb4dec6-2f99-4f9c-86ca-71cebedf4916.png)

**If you try training for the first time, "Oval Track" is recommended.**

![AWS7](https://user-images.githubusercontent.com/84532778/130181452-6cb8ebdf-24df-4936-89f5-6551d1b08c87.png)

---



**4. Race type & Training algorithm**

![AWS8](https://user-images.githubusercontent.com/84532778/130181454-8e054d7b-adfd-47aa-9bf3-bd9b42a78c13.png)

___

You can choose three types of racing. Depending on the race type, you can train with different goals. 

- **Time trial**: race against the clock on an unobstructed track and aim to get the fastest lap time possible.
- **Object avoidance**: race against the clock on a track with stationary obstacles and aim to get the fastest lap time possible.
- **Head-to-head racing**: race against one or more other vehicles on the same track and aim to cross the finish line before other vehicles.

AWS provides PPO and SAC as training algorithms, and if you want to change the hyperparameters, click "Hyperparameters" below in your screen.

if you want to get more information about PPO and SAC, click the link below.

https://docs.aws.amazon.com/deepracer/latest/developerguide/deepracer-how-it-works-reinforcement-learning-algorithm.html

---



**5. Agent** (Choose a vehicle you have.)

![AWS9](https://user-images.githubusercontent.com/84532778/130181457-cdf6d1af-8743-4788-a7bb-b87929431b9e.png)



**6. Reward function**

![AWS10](https://user-images.githubusercontent.com/84532778/130181460-e54c04c8-c31c-4844-abb0-50f297732a01.png)

---

You can edit the reward function code. It will be used to train your model.  If you want to get some example code, click the "Reward function examples". It provides some reward functions for examples and you can train your model with them.

If you want to get some information about "Reward function examples", visit the link below.

https://docs.aws.amazon.com/deepracer/latest/developerguide/deepracer-reward-function-examples.html

If you want to know about the input parameters of AWS DeepRacer reward function, visit the link below.

https://docs.aws.amazon.com/deepracer/latest/developerguide/deepracer-reward-function-input.html

---



**7. Stop conditions**

you can set "Maximum time" for stop conditions.

![AWS11](https://user-images.githubusercontent.com/84532778/130181462-5582e724-8134-415b-a590-2176eb540117.png)

---



## 3. Train your model & Evaluate.

![AWS12](https://user-images.githubusercontent.com/84532778/130181463-ae690abc-5868-4914-be80-c16554f518a9.png)

You can see this screen if you've followed the steps well. It takes time to create a model.

Training will start automatically when the initialization is complete.

---



**1. Training monitor**

![AWS13](https://user-images.githubusercontent.com/84532778/130181466-39187499-d0d1-473b-8c8e-ff2930f7caee.png)

---

You can only watch simulation videos when training is in progress.

As the training progresses, the left graph is drawn. The graph includes three things below.

- Average reward (Training) , green color
- Average percentage completion (Training), Blue color
- Average percentage completion (Evaluating), Red color

You can judge whether the model is well trained and stop training early through reward graphs.

---



**2. Evaluate your model**

if your model have finished training, you can evaluate the model.

![AWS14](https://user-images.githubusercontent.com/84532778/130181470-b3174f1f-0b21-466f-be59-258208b07ac2.png)

---



## 4. Apply physical DeepRacer.

Click "Download phsical car model" to download your trained weight file.

The trained model can be applied to real DeepRacer.

![AWS15](https://user-images.githubusercontent.com/84532778/130181472-7b1569ef-0ac4-4c54-a880-a33e6bbf8ba6.png)



## 5. Connecting the DeepRacer to your computer.

Look at the bottom of your vehicle and make note of the password printed under Host name. You'll need it to log in to the device control console to perform the setup.

![AWS16](https://user-images.githubusercontent.com/84532778/130181475-729afd5d-08b0-457d-a5e6-71c26f9c5a48.jpg)



On your computer, go to https://deepracer.aws to launch the device control console of your vehicle.

![AWS17](https://user-images.githubusercontent.com/84532778/130181476-6510fd31-2a19-479a-9fc8-b32d163534e1.png)

When prompted with a message that the connection is not private or secure, do one of the following. In Chrome, choose Avanced and then choose Proceed to `<device_console_ip_address> (unsafe)`.

Under Unlock your AWS DeepRacer vehicle, enter the password noted in Step 1 and then choose Access vehicle.

Note the IP address shown under Wi-Fi network details. You'll need it to open the vehicle's device control console after the initial setup and any subsequent modification of the Wi-Fi network settings.

Note the IP address shown under Wi-Fi network details. You'll need it to open the vehicle's device control console after the initial setup and any subsequent modification of the Wi-Fi network settings.



![AWS18](https://user-images.githubusercontent.com/84532778/130181477-ee7059ae-56ed-4585-a15e-0739fe01412f.png)

When the connection is complete, the following DeepRacer main console window opens. On this screen, you can upload the model trained on the AWS website. You can also use commands to directly control the vehicle.



## 6. Calibration the DeepRacer

To calibrate the vehicle, click Calibration in the picture above.

![AWS19](https://user-images.githubusercontent.com/84532778/130181479-9a56f3f0-eae7-419d-9f73-94e5f9d3ff69.png)



Calibration can be done in two ways: speed and steering.

![AWS20](https://user-images.githubusercontent.com/84532778/130181480-5d769c1c-b78a-4057-b9e6-ff9160a49400.png)

* ​	Screen to calibrate the steering



![AWS21](https://user-images.githubusercontent.com/84532778/130181481-297deadb-5a25-4669-815b-482349a03377.png)

* Screen to calibrate the speed



**When calibration is complete, return to the main console window to update the model and proceed with the demonstration.**
