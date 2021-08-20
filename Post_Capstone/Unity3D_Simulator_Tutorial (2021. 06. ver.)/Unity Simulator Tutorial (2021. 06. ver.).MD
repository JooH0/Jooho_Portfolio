 	

#  Unity Simulator Tutorial (2021. 06. ver.)

---

### 1. Download Unity-3D Tool

You can download Unity-3D at this link. 

https://store.unity.com/kr/download-nuo

![unity1](https://user-images.githubusercontent.com/84532778/130171766-47b09295-04a5-421d-9b34-7ce8ab42ccd9.png)

---

**Follow several processes for downloading.**

![unity2](https://user-images.githubusercontent.com/84532778/130171772-21739d33-368c-402f-b747-143a7387533e.PNG)

---

![unity3](https://user-images.githubusercontent.com/84532778/130171775-a2c1457d-51ea-45be-ab41-23096a443c25.png)

After downloading, run Unity Hub and you can see the screen below.

### 2. Create project

**You can create project using unity hub.**

![unity4](https://user-images.githubusercontent.com/84532778/130171777-ffd66bbe-671c-4d04-b64a-840a7318458b.png)

---

you should create  a project for 3D template.

Set the project name and storage location.

![unity5](https://user-images.githubusercontent.com/84532778/130171779-c3d30159-1e04-4fcf-9902-8dc5aac14775.PNG)

When you create a project, you can see the same screen as the picture below.

![unity6](https://user-images.githubusercontent.com/84532778/130171781-be6c3a2b-d435-4cf9-bcdb-0c4e27a15ab5.png)

---

### 3. Download Some Packages

**1. Download ML-Agents from Github**

It is important to set Unity and its corresponding Python version and ML-Agents release version. we used ML-Agent-Release 8 in this tutorial.

https://github.com/Unity-Technologies/ml-agents/releases/tag/release_8

you can download the "ML-Agent-Release 8" file from the link above. 

(Storage location is not important.)

![unity7](https://user-images.githubusercontent.com/84532778/130171785-1f7ddc7f-67b9-4b73-bbea-e6373c8ead87.png)

---



Unzip the downloaded file and run the **package manager** on the Unity screen as below.

Install the package file using package manager.

![unity8-2](https://user-images.githubusercontent.com/84532778/130171787-ab1760f0-2940-4bd3-886d-203ef1c5f684.png)

![unity8-1](https://user-images.githubusercontent.com/84532778/130171786-0a850f0e-09d7-436d-a96f-e7adbd959d10.png)

After that, copy paste the entire **"release8\project\Assets\ML-Agents"** folder to the **"Assets"** folder. 

![unity9](https://user-images.githubusercontent.com/84532778/130171790-417b309f-633b-44bf-8e81-629b87445a47.png)

## 4.  Set virtual environment (using Anaconda)

**Use Python-Api for learning with ML-Agents and install Python 3.7 in a new virtual environment for version compatibility. In the release folder, type ‘‘pip3 install -e ./ml-agents-envs’, ’pip install -e ./ML-Agents’ to install various pips, such as tensorflow, numpy, etc.**

![unity10](https://user-images.githubusercontent.com/84532778/130171791-eb66d576-3525-465b-a284-3f3496253ebf.png)

![unity11](https://user-images.githubusercontent.com/84532778/130171793-40c0ebe8-40f6-4c83-ae18-1bd3eff6c31b.png)


```anaconda prompt
pip3 install -e ./ml-agents-envs

pip install -e ./ML-Agents
```




## 5. Prepare training environment

### 5-1. Track line

To create an environment in earnest, new scenes were created in the project, creating plane objects to be used as track in the Hierarchy. 

![unity12](https://user-images.githubusercontent.com/84532778/130171799-6ad63137-4967-4ec7-a0cf-22a989093d62.png)



Drag and drop the **track image file** on the generated plane and resize it.

(you can apply other images.)

![unity13](https://user-images.githubusercontent.com/84532778/130171806-b5621fb4-d5f8-4c97-807c-c672a976c237.png)

---

### 5-2. Using Probuilder tool

Since the important thing in driving learning is that the car does not deviate from the line, use the Probuilder tool to build invisible walls along the line.

Run Package Manager and set the category to "Unity Registry".

![unity14](https://user-images.githubusercontent.com/84532778/130171808-ab2e1114-a964-440a-a5dc-5c001ad8b81c.png)

Search "proBuilder" and install it.

![unity15](https://user-images.githubusercontent.com/84532778/130171809-d3288398-7c4d-4414-af50-5e048cf45c85.png)

After that, you can see "ProBuilder" is created in the tool index.

Click "ProBuilder Window"

![unity16](https://user-images.githubusercontent.com/84532778/130171813-93b8fca9-254b-43d2-9b08-38e5ae87b82e.png)

"Use Icon Mode" helps you understand about the features.

![unity17](https://user-images.githubusercontent.com/84532778/130171817-576f1872-69c0-461a-9dcd-499746774568.png)

Create a virtual wall using "New Polygon Shape".

![unity18](https://user-images.githubusercontent.com/84532778/130171820-0d6ff19a-7010-463c-87ef-e9fae634b2c0.png)

Draw dots using the mouse to make a floor plan.

![unity19](https://user-images.githubusercontent.com/84532778/130171821-419ac64f-1601-451d-b670-93e8440a8794.png)

Drag the green dot upwards to create a 3D shape.

![unity20](https://user-images.githubusercontent.com/84532778/130171823-9206bf20-4f7b-4977-ae4d-c684d491c888.png)

It also creates outer walls in the same way.

![unity21](https://user-images.githubusercontent.com/84532778/130171824-adfd6600-66dd-443a-8327-77f84edee12b.png)

Uncheck "Mesh Renderer" to make it invisible.

![unity22](https://user-images.githubusercontent.com/84532778/130171826-147003ac-73a4-4df8-8f8d-5ed821b8622d.png)

[Result screen]

![unity23](https://user-images.githubusercontent.com/84532778/130171828-b2d84724-ad0a-483f-b621-aabef519611b.png)



---

### 5-3. Car design model (Unity Asset Store)

The track and environment for the car to drive has been completed, an agent must be set. Import an asset from **unity asset store.** 

When downloading the created car's assets, it is recommended rather than creating your own because the default settings such as **car collider**, **wheel collider**, and design are set.

- Unity Asset Store link: https://assetstore.unity.com/?q=low%20poly%20car&orderBy=1

- recommended Asset link: https://assetstore.unity.com/packages/3d/vehicles/land/arcade-free-racing-car-161085

![unity24](https://user-images.githubusercontent.com/84532778/130171830-e7af1f95-f121-43bd-a4e0-a1195759838d.png)

![unity24-0](https://user-images.githubusercontent.com/84532778/130171832-6728f130-b32c-43d0-b7f4-b96cc36b8ba0.png)

<Tip!>

If you want to use visual studio as a coding program, you can change it from the settings as below.![unity24-1](https://user-images.githubusercontent.com/84532778/130171834-f5a1b97b-18b6-49b7-a302-c3a7464bdcce.png)

![unity24-2](https://user-images.githubusercontent.com/84532778/130171839-5105ec53-7889-4435-9537-e2332070de84.png)

---

### 5-4. Using OpenCV tool & setting

Download **OpenCV plus Unity** from the **Unity Asset Store**. 

https://assetstore.unity.com/packages/tools/integration/opencv-plus-unity-85928?locale=ko-KR

![unity25](https://user-images.githubusercontent.com/84532778/130171844-5ef654d5-2050-4e84-9ce6-395d9643b8c8.png)



Install through the Package Manager. It will be used in image-related code.

![unity26](https://user-images.githubusercontent.com/84532778/130171847-dc3d90d4-8a4a-4ecd-a719-cafdbec491cd.png)

---

## Check "Allow  'Unsafe' code"

![unity27](https://user-images.githubusercontent.com/84532778/130171849-36457df1-5c1b-4f10-ab7f-e016d6e8f970.png)

![unity28](https://user-images.githubusercontent.com/84532778/130171850-f25ec688-f81e-479c-b2fc-32732699deb4.png)

![unity29](https://user-images.githubusercontent.com/84532778/130171852-57611278-2fe4-4ee6-9e89-f4777ffa0e65.png)

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

![unity31-1](https://user-images.githubusercontent.com/84532778/130173368-f33b306f-ed6f-4775-9c3e-5cc4a432468f.png)



**Set Car Agent variables**

![unity31](https://user-images.githubusercontent.com/84532778/130171857-ae3a826c-c2ee-478c-9e50-1c874a80f1bc.png)

**The environment and agent are prepared for reinforcement learning, and the agent must set up an observation to receive information from the environment. In this simulation, the camera is attached to the front of the car to set the image of the line to observation. Set up an invisible cube that maintains distance from the car and enter the road conditions (line) at the front of the car, focusing on the cube.**

![unity32](https://user-images.githubusercontent.com/84532778/130173419-29c89a92-0b1d-4a60-9949-3de14d3739c0.png)

Change the background color in the lighting setting so that the camera input image does not include the color of the background.

![unity32-1](https://user-images.githubusercontent.com/84532778/130171867-d7cc832e-e484-4d55-a8c3-9a3934dfae29.png)

![unity32-2](https://user-images.githubusercontent.com/84532778/130171872-ece5e4e0-b045-4b0a-812a-ff415df1ea99.png)

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



![unity33](https://user-images.githubusercontent.com/84532778/130171875-73490ebb-0a31-4967-8d52-f1526ac49dee.png)

**To put the binarized image into the agent's observation value, a new quad is created and filmed in camera.**



### Overall gameObject in Hierachy

---

![unity34](https://user-images.githubusercontent.com/84532778/130171880-2dd4c1e3-c362-4000-833f-eab03707f3ea.png)



**It is necessary to set various parameters for learning. First, the learning rate corresponds to the strength of gradient descent updating each step. Decaying this value until max step, then learning converges more stable. Next, the batch size, which is the number of experiences in each iteration of gradient descent, was appropriately adjusted to meet the specifications of the computer. Parameter beta means intensity of entropy normalization, making the policy random. this allows the agent to navigate the action space during training. This value should be adjusted as the entropy consistently decreases alongside increases in reward.**

![unity35](https://user-images.githubusercontent.com/84532778/130171885-02fd9a55-7145-4c5c-8918-2cd1152e04cf.png)



## Training Agent

**When you are ready for reinforcement learning, move to the current folder and enter the command in a virtual environment created using anaconda prompt. As shown in the figure below, information from the tools required for learning, such as the unity logo and Tensorflow is printed. When simulation is started at unity, each parameter set and the mean reward and std reward (standard deviation of the reward) for each step are printed to the console.**



``` anaconda prompt
conda activate mltest
mlagents-learn params.yaml --run-id=tutorial
```


![unity36](https://user-images.githubusercontent.com/84532778/130171888-86081f60-d07e-4b12-bf1b-d7bf928850b4.png)





**The advantage of simulation in unity is that it can speed up learning by copying the agent and environment and performing multiple trainings at the same time. Training by multiple cars may be faster than training by one car, but it is necessary to select an appropriate number of training as memory may be exceeded depending on your own RAM specification.**

![unity37](https://user-images.githubusercontent.com/84532778/130171897-0a6677ef-6edc-4f57-8ae7-17c0f355af31.png)



## Result Analysis
**There are very useful tool to analysis result. Enter the code below after completing the training or using another anaconda prompt. Then you can see reward, loss , etc. per step.**

``` anaconda prompt
tensorboard --logdir results --port 6006
```

![unity38](https://user-images.githubusercontent.com/84532778/130171900-86a9d065-c69d-4b9d-a468-42ff803032ab.png)



![unity39](https://user-images.githubusercontent.com/84532778/130171901-b30bffe5-2bc0-41af-850c-d6ae90366453.png)

