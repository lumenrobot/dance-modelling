%% Plot time series of gesture
RShld = xlsread(CaptJntFile,9);
RElbw = xlsread(CaptJntFile,10);
RWrst = xlsread(CaptJntFile,11);
%% Right Wrist
subplot(3,1,1);
plot(RWrst(:,1), RWrst(:,2), 'r'); hold on;
plot(RWrst(:,1), RWrst(:,3), 'b'); hold on;
plot(RWrst(:,1), RWrst(:,4), 'k');
title('Right Wrist, X = red, Y = blue, Z = black');
set(gca,'color', [1 1 1]);
xlabel('Time'); ylabel('Real World Coordinates');
%% Right Elbow
subplot(3,1,2);
plot(RElbw(:,1), RElbw(:,2), 'r'); hold on;
plot(RElbw(:,1), RElbw(:,3), 'b'); hold on;
plot(RElbw(:,1), RElbw(:,4), 'k');
title('Right Elbow');
set(gca,'color', [1 1 1]);
xlabel('Time'); ylabel('Real World Coordinates');
%% Right Shoulder
subplot(3,1,3);
plot(RShld(:,1), RShld(:,2), 'r'); hold on;
plot(RShld(:,1), RShld(:,3), 'b'); hold on;
plot(RShld(:,1), RShld(:,4), 'k');
title('Right Shoulder');
set(gca,'color', [1 1 1]);
xlabel('Time'); ylabel('Real World Coordinates');


