clear
clc
a = inputdlg('������Ҫ������еĶ���ֵ:','������ֵ');
a=str2double(a{1});
quotient=1;
if a>= 180
    quotient =floor(a / 180); 
    a = a - quotient * 180;
elseif a <= -180
   quotient = ceil(a / 180); 
   a = a - quotient * 180; 
end
if a==0
   h=warndlg('��������180�ı�������Ϊ�����к�������û������ģ�����');
end
if a>=90
    a = a -180;
elseif a<= -90
    a= a+180;
end
a = a * pi / 180.0; 
cottx = 1.0 / a - a / 3.0 - a^3/ 45 - 2 * a^5/ 945.0;
msgbox(num2str(cottx))