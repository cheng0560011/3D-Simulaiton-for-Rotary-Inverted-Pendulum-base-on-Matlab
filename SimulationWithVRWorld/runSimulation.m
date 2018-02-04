%clear all; clc; close all;

%%

%set parameters ↓
%user can set parameter of controller here ↑

g=0.5*(pi/2);
runParameters; %r參數設定儲存於 runParameters.m 因此比需先執行 runParameters.m
fmodel = sim('CloudLab_simulation.slx'); %本指令用於run simulink


%%

%edit(vrworld('3Danimation_RotaryIP.wrl')) //本指令用於編輯3D模型

%build model and draw 

fpModel = vrworld('3Danimation_RotaryIP.wrl');
open(fpModel);
fig = view(fpModel, '-internal');
vrdrawnow;

alpha = vrnode(fpModel,'rod'); % 設定第一軸的動作對應到alpha array
beta=vrnode(fpModel,'pendulum'); % 設定第二軸的動作對應到beta array

% 以下指令用於gif繪製

f = vrgcf; % this is a handle for capture image
%set(f,'Viewpoint',name of the view in the wrl)
%set(f,'Viewpoint','front');% set viewpoint to front
set(f,'Viewpoint','_untitled_1');% set viewpoint to 45 degree

% the following section is for the dynamic of the structure
for i = 1:200
    alpha.rotation = [0,1,0,alpha_array(i)];
    beta.rotation = [0,0,1,beta_array(i)];
    vrdrawnow;
    image_capture{i} = capture(f);% capture the screen shot from f
    %pause(0.005);//3d animation drawing interval
end


c= clock; % get the current time
fix(c); % round to integer
time = int2str(c); % convert time from interger to char
%% debug the 00 error happens on o'clock
if time(27)==0
    time(27)='0';
end
%%
type='.gif';
name = ['simulation_' time(9) time(10) time(15) time(16) time(21) time(22) time(27) time(28) type]; % generate file name



% the following section is used to generate gif file
for i = 1:200
    [A, map] = rgb2ind(image_capture{i},256);
    if i == 1
        imwrite(A,map,name,'gif','LoopCount',Inf,'DelayTime',0.04);
        imwrite(A,map,'result.gif','gif','LoopCount',Inf,'DelayTime',0.04);
        % to write into image with matrix A and index map, write into the
        % form gif and repeat inf times
    else
        imwrite(A,map,name,'gif','WriteMode','append','DelayTIme',0.04);
        imwrite(A,map,'result.gif','gif','WriteMode','append','DelayTIme',0.04);
        % 'WriteMode' can be set 'append' or 'overwrite'
        
    end
end

% 存兩個.gif，其中檔名會隨時間改變的做紀錄；檔名固定的方便網頁讀檔案

%%


%以下指令用於輸出圖表結果

figure;
plot(alpha_array);
title('alpha');
xlabel('time');
ylabel('alpha(rad)');
saveas(gcf,'alpha.png')
figure;
plot(beta_array);
title('beta');
xlabel('time');
ylabel('beta(rad)');
saveas(gcf,'beta.png')

% 輸出.mat檔結果
% save data as .mat
save('data_alpha_beta','alpha_array','beta_array');



