function result = XCOX( x)
x=x/180*pi;
for n=1:999
    if (x >pi )
        x = x -2* pi;
    end
      if (x < -pi )
       
            x = x + 2*pi;
      end
        if (-pi  <= x && x <= pi )
        
            break;
        end
end
 double result;
 temp=0;
  symbol = 1;
  for  i = 2:2:60
        symbol = symbol * (-1);       
         mi_x = 1;
         jicheng = 1;
        for  j = 1:i
        
            mi_x = mi_x * x;
            jicheng = jicheng * j ;
        end
        temp = temp + symbol * mi_x / jicheng;
  end
 
    result = 1 + temp;
result=round(result,5)