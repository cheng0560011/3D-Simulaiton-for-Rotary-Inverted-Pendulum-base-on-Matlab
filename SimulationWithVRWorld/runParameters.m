clc;
clear;
%% value from manul as real id value
% j0=0.001569    %kg/m^2
j0=0.00215058208333333;
% j1=0.0001785   %kg/m^2
j1=0.000187733333333333;
L0=0.16    ;    %m
l1=0.08   ;     %m
m1=0.022 ;      %m
Ra=2.560403088365053 ;     %ohm
Kt=0.028259462399963;     %Nm/A
Kb=0.01826  ;   %Nm/A
C0=0.118   ;    %Nms
C1=1.2e-05;     %Nms
g=9.81  ;       %m/s^2

rho0=m1*L0*l1;
rho1=j0+m1*L0^2;
rho2=m1*l1^2;
rho3=j1+m1*l1^2;
% rho4=C0+Kt*Kb/Ra
rho4=0+Kt*Kb/Ra;
rho5=C1;
% rho5=0;
rho6=m1*g*l1;
rho7=Kt/Ra;

K1=20;


%% real parameter value
sigma0=(rho0/rho7)*1.2;
sigma1=(rho1/rho7)*1.2;
sigma2=(rho2/rho7)*1.2;
sigma3=(rho3/rho7)*1.2;
sigma4=(rho4/rho7)*1.2;
sigma5=(rho5/rho7)*1.2;
sigma6=(rho6/rho7)*1.2;

sigma001=(rho0/rho7)*1.1;
sigma101=(rho1/rho7)*1.1;
sigma201=(rho2/rho7)*1.1;
sigma301=(rho3/rho7)*1.1;
sigma401=(rho4/rho7)*1.1;
sigma501=(rho5/rho7)*1.1;
sigma601=(rho6/rho7)*1.1;

sigma002=(rho0/rho7)*1;
sigma102=(rho1/rho7)*1;
sigma202=(rho2/rho7)*1;
sigma302=(rho3/rho7)*1;
sigma402=(rho4/rho7)*1;
sigma502=(rho5/rho7)*1;
sigma602=(rho6/rho7)*1;

sigma003=(rho0/rho7)*0.9;
sigma103=(rho1/rho7)*0.9;
sigma203=(rho2/rho7)*0.9;
sigma303=(rho3/rho7)*0.9;
sigma403=(rho4/rho7)*0.9;
sigma503=(rho5/rho7)*0.9;
sigma603=(rho6/rho7)*0.9;

sigma004=(rho0/rho7)*0.8;
sigma104=(rho1/rho7)*0.8;
sigma204=(rho2/rho7)*0.8;
sigma304=(rho3/rho7)*0.8;
sigma404=(rho4/rho7)*0.8;
sigma504=(rho5/rho7)*0.8;
sigma604=(rho6/rho7)*0.8;




% FLC 會噴掉 RUN15秒的時候

% sigma0=(rho0/rho7)*1.6;
% sigma1=(rho1/rho7)*1.6;
% sigma2=(rho2/rho7)*1.6;
% sigma3=(rho3/rho7)*1.6;
% sigma4=(rho4/rho7)*1.6;
% sigma5=(rho5/rho7)*1.6;
% sigma6=(rho6/rho7)*1.6;
% 
% sigma0=(rho0/rho7)*1.6;
% sigma1=(rho1/rho7)*1.6;
% sigma2=(rho2/rho7)*1.6;
% sigma3=(rho3/rho7)*1.6;
% sigma4=(rho4/rho7)*1.6;
% sigma5=(rho5/rho7)*1.6;
% sigma6=(rho6/rho7)*1.6;

sigma01=rho0/rho7;
sigma11=rho1/rho7;
sigma21=rho2/rho7;
sigma31=rho3/rho7;
sigma41=rho4/rho7;
sigma51=rho5/rho7;
sigma61=rho6/rho7;
%% r=0.2,0.1 s壓不下來, 最大到0.55
% % 
% sigma02=sigma01*0.5;
% sigma12=sigma11*0.5;
% sigma22=sigma21*0.5;
% % sigma32=sigma31*0.5;
% sigma42=sigma41*0.5;
% sigma52=sigma51*0.5;
% sigma62=sigma61*0.5;
%%  r=0.2,0.1 s壓不下來, 最大到0.3
% 
% sigma02=sigma01*0.6;
% sigma12=sigma11*0.6;
% sigma22=sigma21*0.6;
% sigma32=sigma31*0.6;
% sigma42=sigma41*0.6;
% sigma52=sigma51*0.6;
% sigma62=sigma61*0.6;
%% r=0.2 不行 ,到0.083
% 
% sigma02=sigma01*0.7;
% sigma12=sigma11*0.7;
% sigma22=sigma21*0.7;
% sigma32=sigma31*0.7;
% sigma42=sigma41*0.7;
% sigma52=sigma51*0.7;
% sigma62=sigma61*0.7;
%% OK 6.0e-03 FINAL
sigma02=sigma01*0.8;
sigma12=sigma11*0.8;
sigma22=sigma21*0.8;
sigma32=sigma31*0.8;
sigma42=sigma41*0.8;
sigma52=sigma51*0.8;
sigma62=sigma61*0.8;



%%
% A=[0 1 0 0;0 0 0 0;0 0 0 1;0 0 52.483 -sigma51/sigma31];
A=[0 1 0 0;0 0 0 0;0 0 0 1;0 0 52.483 0];
B=[0;1;0;0.856];
C=[0 1 0 0];
D=[0];
eig(A);
Sc=[B A*B A^2*B A^3*B];%ctrb(A,B)
rank(Sc);
det(Sc);
% ans =
 
%     7.2494
% %    -7.2494
%          0
%          0
% P=[-7 -2 -3+i -3-i]; %正常
P=[-7 -2 -3+2*i -3-2*i];% K=15 但是沒有ABS(BETA)
K=place(A,B,P);



%% feed K value here 
% K =
%    -2.6675   -3.3154  155.5497   21.3964

% Kd;
%  Kd=[-9.8009 -214.4438   -6.2241  -10.4768]   % for test only
% P=[-7 -3 -6+i -6-i] %EXPERIMEANAL
%% for controller vs
vs1=-sigma01*sigma21/sigma31; %right
vs2=sigma01*sigma51/sigma31;  %right
vs3=-sigma01*sigma61/sigma31; %right
vs4=2*sigma21; %right
vs5=sigma41;   %right
vs6=sigma01;   %right

%% for controller w
w1=abs(sigma02*sigma22/sigma32);%right e2
w2=abs(sigma02*sigma52/sigma32);%right e3
w3=abs(sigma02*sigma62/sigma32);%right e4
w4=2*abs(sigma22);%right e5
w5=abs(sigma42);%right e6
w6=abs(sigma02);%right e1

w7=abs(sigma12+sigma22+sigma02*sigma02/sigma32);%right e delta

