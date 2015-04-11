function [x y] = op_rotate(x, y, xc, yc, theta)

%% Rotate (x,y), degree of theta, relative to (xc, yc)


rotatemat = [cos((theta/180)*pi) -sin((theta/180)*pi);...
			sin((theta/180)*pi) cos((theta/180)*pi)];

answ = rotatemat*[x-xc; y-yc];
x = answ(1);
y = answ(2);