function [output] = tan1(input)
%UNTITLED3 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
    if input > 1048576.0 %�������2^20
		output = inf;
        return
    end
    if rem(input, 180) == 90
		output = inf;
        return
    end
    %��������д���ʹ��������-90��+90��Χ��
    x = rem(input, 180);%�������ϵĵ�ȫ��ӳ�䵽-180��180��,��ʱx��ȡֵ��ΧΪ-180��180,��Ҫ�ٽ���ѹ��Ϊ-90��90
    if x > 90
        x = x - 180;%��90-180�ϵĵ�ӳ��Ϊ-90-0
    elseif x < -90
        x = x + 180;%��-180--90�ĵ�ӳ��Ϊ0-90
    end
    %��������ֵ
    if x == 45
        output = 1;
        return
    end
    if x == -45
        output = -1;
        return
    end

	pi = 3.14159265358979323846;
	y = x / 180 * pi;	%���Ƕ�����ת��Ϊ��������

	output = y+  (1.0/3.0) * power(y,3) +  (2.0/15.0) * power(y,5) +  (17.0/315.0) * power(y,7)  +  (62.0/2835.0) * power(y,9) ;
 end