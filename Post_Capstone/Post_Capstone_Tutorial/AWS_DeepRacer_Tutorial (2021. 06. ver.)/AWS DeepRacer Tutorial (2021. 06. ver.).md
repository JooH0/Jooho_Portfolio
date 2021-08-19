# AWS DeepRacer Tutorial (2021. 06. ver.)

---

## 1. Enter AWS website to prepare for DeepRacer training.

https://console.aws.amazon.com/deepracer/home?region=us-east-1#welcome

**1. You can see the AWS DeepRacer homepage through the link above.**

![image-20210625165231103](https://user-images.githubusercontent.com/84532778/123618695-67c05b00-d843-11eb-8e5d-7ec789efd4df.png)



**2. Click on the banner on the left side of the window.**

![image-20210625165618410](https://user-images.githubusercontent.com/84532778/123618700-6858f180-d843-11eb-9f19-24fb8df447a5.png)



**3. You can see several menus for reinforcement Learning.**

![image-20210625180006872](https://user-images.githubusercontent.com/84532778/123618714-6b53e200-d843-11eb-9077-47973c748187.png)

---

**Get started** : you can create model.

**Your models** : you can see the models you made before.

**Your garage** : you can configure your vehicle with one or more sensors, choose a neural 			            network topology, and customize the action space to meet your racing criteria.

---



## 2. Create your reinforcement learning model

**1. Click the "Get started" for creating your custom model**

![image-20210625180145025](https://user-images.githubusercontent.com/84532778/123618716-6bec7880-d843-11eb-9b4a-c73482b5c8f2.png)

---

**start the course :** You can get basic reinforcement learning knowledge and general 							      information about DeepRacer (It takes about 10 minutes).

---



**2. Create your custom model** (Follow the steps provided by AWS)

Enter the name of your model.

![image-20210625181544680](https://user-images.githubusercontent.com/84532778/123618723-6db63c00-d843-11eb-8435-3c78cdc4cf10.png)

---



**3. Choose a course you want to simulate.**

![image-20210625182043051](https://user-images.githubusercontent.com/84532778/123618726-6e4ed280-d843-11eb-9378-9d25fd7ffe65.png)

**If you try training for the first time, "Oval Track" is recommended.**

![image-20210625182540680](https://user-images.githubusercontent.com/84532778/123618731-6ee76900-d843-11eb-894f-e1043798ab58.png)

---



**4. Race type & Training algorithm**

![image-20210625183758381](https://user-images.githubusercontent.com/84532778/123618745-7149c300-d843-11eb-92b9-556ea67a4167.png)

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

![image-20210625183850343](https://user-images.githubusercontent.com/84532778/123618756-73138680-d843-11eb-9494-f76554ea7a81.png)



**6. Reward function**

![image-20210625184330224](https://user-images.githubusercontent.com/84532778/123618764-7444b380-d843-11eb-91dd-5012b5db2f56.png)

---

You can edit the reward function code. It will be used to train your model.  If you want to get some example code, click the "Reward function examples". It provides some reward functions for examples and you can train your model with them.

If you want to get some information about "Reward function examples", visit the link below.

https://docs.aws.amazon.com/deepracer/latest/developerguide/deepracer-reward-function-examples.html

If you want to know about the input parameters of AWS DeepRacer reward function, visit the link below.

https://docs.aws.amazon.com/deepracer/latest/developerguide/deepracer-reward-function-input.html

---



**7. Stop conditions**

you can set "Maximum time" for stop conditions.

![image-20210625185250983](https://user-images.githubusercontent.com/84532778/123618773-76a70d80-d843-11eb-8a0f-41dfc1c3fdb2.png)

---



## 3. Train your model & Evaluate.

![image-20210625185641940](https://user-images.githubusercontent.com/84532778/123618777-773fa400-d843-11eb-902a-992425af62d6.png)

You can see this screen if you've followed the steps well. It takes time to create a model.

Training will start automatically when the initialization is complete.

---



**1. Training monitor**

![image-20210625190426294](https://user-images.githubusercontent.com/84532778/123618782-77d83a80-d843-11eb-88f6-ef0a14d50c27.png)

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

![image-20210625191410043](https://user-images.githubusercontent.com/84532778/123618784-79096780-d843-11eb-857c-61d02c1310be.png)

---



## 4. Apply physical DeepRacer.

Click "Download phsical car model" to download your trained weight file.

The trained model can be applied to real DeepRacer.

![image-20210625192325393](https://user-images.githubusercontent.com/84532778/123618790-7a3a9480-d843-11eb-8f16-7d3d0055d55e.png)



## 5. Connecting the DeepRacer to your computer.

Look at the bottom of your vehicle and make note of the password printed under Host name. You'll need it to log in to the device control console to perform the setup.

![DeepRacer_password](https://user-images.githubusercontent.com/84532778/123619297-01880800-d844-11eb-9652-d3475bae7073.jpg)



On your computer, go to https://deepracer.aws to launch the device control console of your vehicle.

![AWS_login_page](https://user-images.githubusercontent.com/84532778/123619277-fd5bea80-d843-11eb-8c68-28542225e478.png)

When prompted with a message that the connection is not private or secure, do one of the following. In Chrome, choose Avanced and then choose Proceed to `<device_console_ip_address> (unsafe)`.

Under Unlock your AWS DeepRacer vehicle, enter the password noted in Step 1 and then choose Access vehicle.

Note the IP address shown under Wi-Fi network details. You'll need it to open the vehicle's device control console after the initial setup and any subsequent modification of the Wi-Fi network settings.

Note the IP address shown under Wi-Fi network details. You'll need it to open the vehicle's device control console after the initial setup and any subsequent modification of the Wi-Fi network settings.





![Control_vehicle](https://user-images.githubusercontent.com/84532778/123619291-0056db00-d844-11eb-9c6d-66831c66ec2e.png)

When the connection is complete, the following DeepRacer main console window opens. On this screen, you can upload the model trained on the AWS website. You can also use commands to directly control the vehicle.



## 6. Calibration the DeepRacer



To calibrate the vehicle, click Calibration in the picture above.

![Calibration_main](https://user-images.githubusercontent.com/84532778/123619289-ffbe4480-d843-11eb-9f9a-5676c408b3fc.png)



Calibration can be done in two ways: speed and steering.



![Calibrate_steer](https://user-images.githubusercontent.com/84532778/123619285-ff25ae00-d843-11eb-943b-a04827dcb2f2.png)

* ​	Screen to calibrate the steering



![Calibrate_Speed](https://user-images.githubusercontent.com/84532778/123619282-fe8d1780-d843-11eb-83ce-a70acbbefd6e.png)

* Screen to calibrate the speed



**When calibration is complete, return to the main console window to update the model and proceed with the demonstration.**
