# 3D Simulaiton for Rotary Inverted Pendulum base on Matlab

本專題使用兩種不同的方式做旋轉式導立單擺的模擬與繪圖
分別為Simscape 與 VRWorld
以下為介紹

This project used two different processes to realize the 3D animation of simulation for Rotary Inverted Pendulum :
Simscape and VRWorld
Following is the introduction

# Simulation with Simscape
位置 : SimulationWithSimscape
本模擬使用Matlab中的物理建模工具
打開pend_v2.slx之後按下開始，會在Matlab的視窗上出現3D動畫
Simulink Library 中的 Simscape 目錄中的 Multibody 目錄
Simulink > Simscape > Multibody
可以建立機構，機構內部每個零件可以輸入物理特性，每個零件可以設定相對座標，旋轉關節上可以輸入扭力
在Simulink中建立機構然後設定初始角度或初始位置後可以做機構動態的模擬

網路介紹(英文) : https://www.youtube.com/watch?v=ERrf7qtV4e0
(提供Simcape導覽)

網路教學(中文) : https://www.mathworks.com/videos/quadcopter-simulation-and-control-made-easy-116297.html
(提供物理機構建立與教學)

# Simulation With VRWorld
位置 : SimulationWithVRWorld/
注意 : 常見的Matlab版本有Matlab 2013 與 Matlab 2016
Simulink 3D Animation可以在Matlab 2013a 與 Matlab2013b執行
雲端實驗室使用Matlab 2013a

使用方式為用Matlab開啟rumSimulation.m並執行runSimulation.m

本3D模擬利用Matlab Simulink建立數學模型，Simulink模擬完成之後輸出array
Simulink 3D Animation會根據輸出的Array進行繪圖
本模擬在Simulink Editor中使用Run即可，.m檔中有呼叫.slx進行模擬與輸出模擬結果的指令

在Matlab的Preferance中的Simulink 3D Animation目錄有VRML Editor可以改變3D模型的Editor
建議使用V-Realm Builder(預設選項可能非V-RealmBuilder)
編輯3D模型時使用


Mathwork簡介 : https://www.mathworks.com/help/sl3d/index.html
教學(英文) : https://www.mathworks.com/videos/getting-started-with-simulink-3d-animation-part-1-build-a-simulink-model-68731.html
(提供一個已知的物理模型與結果，以VR World動畫作呈現)

Good Luck
