
# Need4Stek

## <img width="26px" src="https://newsroom.ionis-group.com/wp-content/uploads/2018/12/epitech-logo-signature-quadri.png"/> Epitech project :

Algorithm for an automous car in C, using CoppeliaSim.

copelia : <a>https://www.coppeliarobotics.com/files/CoppeliaSim_Edu_V4_3_0_Ubuntu20_04.tar.xz</a>

link to the PDF : https://intra.epitech.eu/module/2022/B-AIA-200/NAN-2-1/acti-592362/project/#!/group
---

### :pencil: CoppeliaSim description :
   CoppeliaSim is a simulator created by Coppelia Robotics. It enables the creation and control of robots.
For this project, we have built a virtual track and car that you will use to implement for AI.
\

By now you’ve understood that it’s now your turn to create your own autonomous car. It must be capable
of driving on a track without hitting the walls or driving in the wrong direction.\
In order to help you with this task, several tools are avaible:\

• CoppeliaSim is a simulator created by Coppelia Robotics. It enables the creation and control of robots.
 For this project, we have built a virtual track and car that you will use to implement for AI. You will find,
further on in this document, how to install/use this software on your machine,\
\
• an API (binary name: n4s). It is a communication interface that offers an array of actions that you can\
 use (start a simulation, set the car motor’s speed, wheel angle,. . . ). You can also use it alone in order\
 to test the communication protocol on the command line. This communication protocol is defined\
 further on,\
 \
 • a shell script (binary name: pipes.sh) that enables you to connect your program to the API and launch\
simulations. It’s a binary that you will run in order to test your AI. Its utilization is also presented further on.\

---

### :computer: Commands :
```
START_SIMULATION    
STOP_SIMULATION     
CAR_FORWARD:float    [0;1]
CAR_BACKWARDS:float  [0;1]
WHEELS_DIR:float     [-1;1]
GET_INFO_LIDAR
GET_CURRENT_SPEED
GET_CURRENT_WHEELS
CYCLE_WAIT:int       [0; INT_MAX]
GET_CAR_SPEED_MAX
GET_CAR_SPEED_MIN
GET_INFO_SIMTIME
```

---

### :exclamation: Rule :
> All the commands ends with "\n".

---

### :no_entry_sign: Disclaimer :
only libc and maths is allow to this project !

---
