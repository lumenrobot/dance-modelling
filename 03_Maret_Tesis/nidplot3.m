%% Plot time series of gesture
RShld = xlsread(CaptJntFile,9);
RElbw = xlsread(CaptJntFile,10);
RWrst = xlsread(CaptJntFile,11);
%% Plot the gesture
plot3(RWrst(:,4), RWrst(:,2), RWrst(:,3), 'm'); hold on;
plot3(RElbw(:,4), RElbw(:,2), RElbw(:,3), 'b'); hold on;
plot3(RShld(:,4), RShld(:,2), RShld(:,3), 'k'); 
xlabel('Z'); ylabel('X'); zlabel('Y');
set(gca,'color', [1 1 1]);
fprintf('The data has been plotted :)\n'); pause(1);


