% rbr = importdata('G:\flipcode\flipcode\realBr.txt');
% rbg = importdata('G:\flipcode\flipcode\realBg.txt');
% rbb = importdata('G:\flipcode\flipcode\realBb.txt');
% acr = importdata('G:\flipcode\flipcode\accb.txt');
% acg = importdata('G:\flipcode\flipcode\accg.txt');
% acb = importdata('G:\flipcode\flipcode\accb.txt');
% dir = importdata('G:\flipcode\flipcode\dirLCr.txt');
% dig = importdata('G:\flipcode\flipcode\dirLCg.txt');
% dib = importdata('G:\flipcode\flipcode\dirLCb.txt');
ra =  importdata('G:\flipcode\flipcode\newalphar.txt');
ga =  importdata('G:\flipcode\flipcode\newalphag.txt');
ba =  importdata('G:\flipcode\flipcode\newalphab.txt');
% ra = (acr - rbr) ./ (dir - rbr);
% ga = (acg - rbg) ./ (dig - rbg);
% ba = (acb - rbb) ./ (dib - rbb);
%  ray=imread('I:\raytracing\ray.png');
%  rgb(:,:,1)=r;
%  rgb(:,:,2)=b;
%  rgb(:,:,3)=c;
 gray = (30*ra+59*ga+11*ba)/100;
  gray=uint8(gray*255);
for i=1:660
for j = 1:1000
if gray(i,j)~=0&&gray(i,j)~=255
gray(i,j)=128;
end   

% if gray(i,j) <254 && gray(i,j)>128
%     gray(i,j) = 128;
% end
% if gray(i,j) >240
%     gray(i,j) = 255;
% end
end
end
 imshow(ga)
% imshow(r); 
% imshow(rgb); 
%  a=imread('C:\Users\Administrator\Desktop\hahah.png');
%  for i=1:660
% for j = 1:1000
% for m=1:3
% ray(i,j,m)=ray(i,j,m)*gray(i,j);
% 
% end
% end
%  end
%  imshow(rgb);