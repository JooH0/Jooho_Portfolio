 	

#  Unity Simulator Tutorial (2021. 06. ver.)

---

### 1. Download Unity-3D Tool

You can download Unity-3D at this link. 

https://store.unity.com/kr/download-nuo

![1](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\1.png)

---

**Follow several processes for downloading.**

![5](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\5.PNG)

---

![4](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\4.PNG)

After downloading, run Unity Hub and you can see the screen below.

### 2. Create project

**You can create project using unity hub.**

![image-20210625171136294](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\image-20210625171136294.png)

---

you should create  a project for 3D template.

Set the project name and storage location.

![11](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\11.PNG)

When you create a project, you can see the same screen as the picture below.

![image-20210625172623109](https://user-images.githubusercontent.com/59379790/123419092-ccd24180-d5f4-11eb-9053-666bdfb14356.png)

---

### 3. Download Some Packages

**1. Download ML-Agents from Github**

It is important to set Unity and its corresponding Python version and ML-Agents release version. we used ML-Agent-Release 8 in this tutorial.

https://github.com/Unity-Technologies/ml-agents/releases/tag/release_8

you can download the "ML-Agent-Release 8" file from the link above. 

(Storage location is not important.)

![6](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\6.png)

---



Unzip the downloaded file and run the **package manager** on the Unity screen as below.

Install the package file using package manager.

![22](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\22.png)

![image-20210625202553317](https://user-images.githubusercontent.com/59379790/123419141-d491e600-d5f4-11eb-8d28-21ca5afaa377.png)

After that, copy paste the entire **"release8\project\Assets\ML-Agents"** folder to the **"Assets"** folder. 

![set5](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\set5.png)

## 4.  Set virtual environment (using Anaconda)

**Use Python-api for learning with ML-Agents and install Python 3.7 in a new virtual environment for version compatibility. In the release folder, type ‘‘pip3 install -e ./ml-agents-envs’, ’pip install -e ./ML-Agents’ to install various pips, such as tensorflow, numpy, etc.**

![image-20210625172745218](https://user-images.githubusercontent.com/59379790/123419094-ccd24180-d5f4-11eb-9539-3e60d9ed762a.png)

![image-20210625201159121](https://user-images.githubusercontent.com/59379790/123419136-d3f94f80-d5f4-11eb-9cc3-c292dac5332b.png)


```anaconda prompt
pip3 install -e ./ml-agents-envs

pip install -e ./ML-Agents
```




## 5. Prepare training environment

### 5-1. Track line

To create an environment in earnest, new scenes were created in the project, creating plane objects to be used as track in the Hierarchy. 

![image-20210625174313890](https://user-images.githubusercontent.com/59379790/123419098-ce036e80-d5f4-11eb-95e7-4867896b6889.png)



Drag and drop the **track image file** on the generated plane and resize it.

(you can apply other images.)

![image-20210625174342210](https://user-images.githubusercontent.com/59379790/123419100-ce9c0500-d5f4-11eb-9657-c991c5aa463a.png)

---

### 5-2. Using Probuilder tool

Since the important thing in driving learning is that the car does not deviate from the line, use the Probuilder tool to build invisible walls along the line.

Run Package Manager and set the category to "Unity Registry".

![pro1](C:\Users\rlawn\Downloads\images\images\pro1.png)

Search "proBuilder" and install it.

![pro2](C:\Users\rlawn\Downloads\images\images\pro2.png)

After that, you can see "ProBuilder" is created in the tool index.

Click "ProBuilder Window"

![pro3](C:\Users\rlawn\Downloads\images\images\pro3.png)

"Use Icon Mode" helps you understand about the features.

![pro4](C:\Users\rlawn\Downloads\images\images\pro4.png)

Create a virtual wall using "New Polygon Shape".

![pro5](C:\Users\rlawn\Downloads\images\images\pro5.png)

Draw dots using the mouse to make a floor plan.

![pro7](C:\Users\rlawn\Downloads\images\images\pro7.png)

Drag the green dot upwards to create a 3D shape.

![pro8](C:\Users\rlawn\Downloads\images\images\pro8.png)

It also creates outer walls in the same way.

![pro9](C:\Users\rlawn\Downloads\images\images\pro9.png)

Uncheck "Mesh Renderer" to make it invisible.

![pro10](C:\Users\rlawn\Downloads\images\images\pro10.png)

[Result screen]

![pro11](C:\Users\rlawn\Downloads\images\images\pro11.png)



---

### 5-3. Car design model (Unity Asset Store)

The track and environment for the car to drive has been completed, an agent must be set. Import an asset from **unity asset store.** 

When downloading the created car's assets, it is recommended rather than creating your own because the default settings such as car collider, wheel collider, and design are set.

- Unity Asset Store link: https://assetstore.unity.com/?q=low%20poly%20car&orderBy=1

- recommended Asset link: https://assetstore.unity.com/packages/3d/vehicles/land/arcade-free-racing-car-161085

![7](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\7.png)



---

### 5-4. Using OpenCV tool & setting

Download **OpenCV plus Unity** from the **Unity Asset Store**. 

https://assetstore.unity.com/packages/tools/integration/opencv-plus-unity-85928?locale=ko-KR

![8](C:\Users\rlawn\OneDrive\바탕 화면\typora-user-images\8.png)



Install through the Package Manager. It will be used in image-related code.

![1 (6)](C:\Users\rlawn\Downloads\images\images\1 (6).png)

---

## Check "Allow  'Unsafe' code"

![set2](C:\Users\rlawn\Downloads\images\images\set2.png)

![set3](C:\Users\rlawn\Downloads\images\images\set3.png)

![set4](C:\Users\rlawn\Downloads\images\images\set4.png)

## 6. Code Script

**The script to enter the agent uses C# language. **

``` C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using Unity.MLAgents;
using Unity.MLAgents.Actuators;
using Unity.MLAgents.Sensors;
using OpenCvSharp.Demo;
public class CarAgent : Agent 
// public class뒤의 이름(CarAgent)은 파일명과 동일하게 해줘야함
{
    //초기화 작업을 위해 한번 호출되는 메소드
    private float horizontalInput;
    private float verticalInput;
    private float reward;
    public Transform tr;
    private Texture2D input_img;

    public WheelCollider frontLeftWheelCollider;
    public WheelCollider frontRightWheelCollider;
    public WheelCollider rearLeftWheelCollider;
    public WheelCollider rearRightWheelCollider;
    public Transform frontLeftWheelTransform;
    public Transform frontRightWheelTransform;
    public Transform rearLeftWheelTransform;
    public Transform rearRightWheelTransform;
    public float episodes;
    public float steerAngle = 30f;
    public float motorForce = 25f;
    public override void Initialize()
    {
        episodes = 0;
        tr = GetComponent<Transform>(); //agent의 위치값
        tr.localPosition = new Vector3(5.7f, 0, -7.15f);
        tr.localRotation = Quaternion.Euler(0f, 90.0f, 0.0f);
        frontLeftWheelCollider.motorTorque = 0;
        frontRightWheelCollider.motorTorque = 0;
        frontLeftWheelCollider.steerAngle = 0;
        frontRightWheelCollider.steerAngle = 0;
        reward = 0;
    }

    //에피소드(학습단위)가 시작할때마다 호출
    public override void OnEpisodeBegin()
    {
        episodes += 1;
        tr.localPosition = new Vector3(5.7f, 0, -7.15f);
        tr.localRotation = Quaternion.Euler(0f, 90.0f, 0.0f);
        frontLeftWheelCollider.motorTorque = 0;
        frontRightWheelCollider.motorTorque = 0;
        frontLeftWheelCollider.steerAngle = 0;
        frontRightWheelCollider.steerAngle = 0;
        UpdateWheelPos(frontLeftWheelCollider, frontLeftWheelTransform);
        UpdateWheelPos(frontRightWheelCollider, frontRightWheelTransform);
        UpdateWheelPos(rearLeftWheelCollider, rearLeftWheelTransform);
        UpdateWheelPos(rearRightWheelCollider, rearRightWheelTransform);
        reward = 0;
    }

    private void UpdateWheelPos(WheelCollider wheelCollider, Transform trans)
    {
        
        Vector3 pos;
        Quaternion rot;
        wheelCollider.GetWorldPose(out pos, out rot);
        trans.rotation = rot;
        trans.position = pos;
    }
    //브레인(정책)으로 부터 전달 받은 행동을 실행하는 메소드

    public override void OnActionReceived(float[] vectorAction)
    {
        int angle = 0;

        int moveX = Mathf.FloorToInt(vectorAction[0]);
        if (moveX == 0) { angle = 0; }
        if (moveX == 1) { angle = -1; }
        if (moveX == 2) { angle = 1; }

        frontLeftWheelCollider.steerAngle = angle * steerAngle;
        frontRightWheelCollider.steerAngle = angle * steerAngle;
        frontLeftWheelCollider.motorTorque = motorForce;
        frontRightWheelCollider.motorTorque = motorForce;

        UpdateWheelPos(frontLeftWheelCollider, frontLeftWheelTransform);
        UpdateWheelPos(frontRightWheelCollider, frontRightWheelTransform);
        UpdateWheelPos(rearLeftWheelCollider, rearLeftWheelTransform);
        UpdateWheelPos(rearRightWheelCollider, rearRightWheelTransform);
        
        //reward
        AddReward(0.01f);
        reward += 0.01f;
        if (reward>1000)
        {
            EndEpisode();
        }
        Resources.UnloadUnusedAssets();
    }

    void OnCollisionEnter(Collision collision)
    {
        EndEpisode();
        Resources.UnloadUnusedAssets();
    }

    public override void Heuristic(float[] actionsOut)
    {
        actionsOut[0] = Input.GetAxisRaw("Horizontal"); 
    }
}
```



**Set wheel collider variables**

![image-20210625175448526](https://user-images.githubusercontent.com/59379790/123419111-cfcd3200-d5f4-11eb-9f6b-48206122bc44.png)



**Set Car Agent variables**

![image-20210625175614147](https://user-images.githubusercontent.com/59379790/123419113-d065c880-d5f4-11eb-90df-9256b776fd18.png)

**The environment and agent are prepared for reinforcement learning, and the agent must set up an observation to receive information from the environment. In this simulation, the camera is attached to the front of the car to set the image of the line to observation. Set up an invisible cube that maintains distance from the car and enter the road conditions (line) at the front of the car, focusing on the cube.**

![image-20210625180239848](https://user-images.githubusercontent.com/59379790/123419116-d0fe5f00-d5f4-11eb-8b9e-874214010599.png)

```C#
using UnityEngine;
using System.Collections;

public class SmoothFollow : MonoBehaviour
{
    public Transform target;
    public float distance = 1.6f;
    public float height = 0.4f;
    public float damping = 0.7f;
    public bool smoothRotation = true;
    public bool followBehind = true;
    public float rotationDamping = 50.0f;

    void FixedUpdate()
    {

        Vector3 wantedPosition;
        if (followBehind)
            wantedPosition = target.TransformPoint(0, height, -distance);
        else
            wantedPosition = target.TransformPoint(0, height, distance);

        transform.position = Vector3.Lerp(transform.position, wantedPosition, damping);

        if (smoothRotation)
        {
            Quaternion wantedRotation = Quaternion.LookRotation(target.position - transform.position, target.up);
            transform.rotation = Quaternion.Slerp(transform.rotation, wantedRotation, Time.deltaTime * rotationDamping);
        }
        else transform.LookAt(target, target.up);
    }
}
```



**It is adjusted that the resolution of the front camera from 640×480 to 64×48 to export the weight file of the simulation results to the embedded GPU for real-world implementation and to reduce the amount of information, the three-channel BGR image was replaced with grayscale and thresholding black and white. Because this image is used as an observation by the agent, the camera object is set as a child object of car and the camera sensor script is added to the inspector. Observation stack is a value indicating how many observations to perform or how many tasks should be selected, set to 2 to select tasks using the current image and previous step image.**

![image-20210625180542451](https://user-images.githubusercontent.com/59379790/123419120-d196f580-d5f4-11eb-84e8-ac6ab55893fb.png)

**To put the binarized image into the agent's observation value, a new quad is created and filmed in camera.**



### Overall gameObject in Hierachy

![image-20210625181136259](https://user-images.githubusercontent.com/59379790/123419122-d196f580-d5f4-11eb-8538-340ce0e1df0e.png)





**It is necessary to set various parameters for learning. First, the learning rate corresponds to the strength of gradient descent updating each step. Decaying this value until max step, then learning converges more stable. Next, the batch size, which is the number of experiences in each iteration of gradient descent, was appropriately adjusted to meet the specifications of the computer. Parameter beta means intensity of entropy normalization, making the policy random. this allows the agent to navigate the action space during training. This value should be adjusted as the entropy consistently decreases alongside increases in reward.**

![image-20210625181252772](https://user-images.githubusercontent.com/59379790/123419123-d22f8c00-d5f4-11eb-9cfb-f99e661b6371.png)



## Training Agent

**When you are ready for reinforcement learning, move to the current folder and enter the command in a virtual environment created using anaconda prompt. As shown in the figure below, information from the tools required for learning, such as the unity logo and Tensorflow is printed. When simulation is started at unity, each parameter set and the mean reward and std reward (standard deviation of the reward) for each step are printed to the console.**



``` anaconda prompt
conda activate mltest
mlagents-learn params.yaml --run-id=tutorial
```


![image-20210625181524837](https://user-images.githubusercontent.com/59379790/123419129-d2c82280-d5f4-11eb-99d1-19db988b4e0a.png)





**The advantage of simulation in unity is that it can speed up learning by copying the agent and environment and performing multiple trainings at the same time. Training by multiple cars may be faster than training by one car, but it is necessary to select an appropriate number of training as memory may be exceeded depending on your own RAM specification.**

![image-20210625181558500](https://user-images.githubusercontent.com/59379790/123419131-d360b900-d5f4-11eb-89b9-b0478b01a903.png)



## Result Analysis
**There are very useful tool to analysis result. Enter the code below after completing the training or using another anaconda prompt. Then you can see reward, loss , etc. per step.**

``` anaconda prompt
tensorboard --logdir results --port 6006
```

![image-20210625182323737](https://user-images.githubusercontent.com/59379790/123419133-d360b900-d5f4-11eb-87b7-ba1ffc79af2d.png)



![image-20210625182338276](https://user-images.githubusercontent.com/59379790/123419134-d3f94f80-d5f4-11eb-899c-a09c22b60a03.png)
