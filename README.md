# moveit-panda-pick-place
# 🦾 MoveIt! Panda Pick & Place 🚀
**Motion Planning for the Panda Robotic Arm using MoveIt in ROS2**

## 📌 Overview
This project demonstrates a **pick and place** operation using the **Franka Emika Panda** robotic arm in a simulated environment.  
It utilizes **MoveIt! Motion Planning Framework in ROS2 Humble** to navigate from a start position to pick and drop locations while avoiding obstacles.

## 🔧 Technologies Used
- **ROS2 Humble**
- **MoveIt!** for motion planning
- **Gazebo/RViz2** for visualization
- **Docker** for environment setup
- **Python / C++** for scripting

## 🚀 Features
✅ Motion planning from **start → pick → place → start**  
✅ **Obstacle avoidance** using MoveIt collision detection  
✅ **Gripper control** (closing at pick position, opening at drop position)  
✅ **Docker setup** for easy deployment  

## 🎥 Demonstration
📌 **Pick & Place Motion Execution:** [YouTube / Google Drive Link](https://drive.google.com/file/d/1kHcS7kFjkhUFbJwtoFVx8vWU9qWltUUM/view?usp=drive_link)  
📌 **MoveIt Setup Assistant Configuration:** [YouTube / Google Drive Link](https://drive.google.com/file/d/14clT_OkzqwR2S2ZiLz7Acor9MKTjNzmT/view?usp=drive_link)  

## 🛠️ Installation & Running
### 1️⃣ **Set up Docker & ROS2 Humble**

sudo snap install docker
sudo groupadd docker 
sudo usermod -aG docker ${USER} 
sudo chmod 666 /var/run/docker.sock 

### 2️⃣ **Build and Run Docker Container**
cd Project4_docker
docker build . –t project4
./create_container.sh panda_container
docker start panda_container
./open_terminal.sh panda_container

### 3️⃣ **Run the Motion Planning Demo**
source install/setup.bash
ros2 launch panda_configuration demo.launch.py

