#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
char getSignal()//运算符 
{
    char signal[4]={'+','-','x','/'};
    return signal[rand()%4];
}
int random(int a)//随机数 
{
	int b;
    b=rand()%a+1;
	return b;
}
int gcd(int x,int y)//辗转相除法 
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int answers(int y,int num,int num1,int num2,int num3,int num4,char signal1,char signal2,char signal3,int r)//生成答案 
{
	int question(int y,int r);
	int ans,a,c=0;
	FILE *fp;
	fp=fopen("Answers.txt","a");
	if(num==1)
	{
		int ans1,ans2;
		switch(signal1)
		{
			case '+':
				ans=num1+num2;
			    fprintf(fp,"题目%d:%d %c %d = %d\n",y,num1,signal1,num2,ans);
			    fclose(fp);break;
			case '-':
				if(num1<num2)question(y,r);
				else
				{
					ans=num1-num2;
			        fprintf(fp,"题目%d:%d %c %d = %d\n",y,num1,signal1,num2,ans);
			        fclose(fp);break;
				}
			case 'x':
				ans=num1*num2;
			    fprintf(fp,"题目%d:%d %c %d = %d\n",y,num1,signal1,num2,ans);
			    fclose(fp);break;
			case '/':
				a=gcd(num1,num2);
				ans1=num1/a;
				ans2=num2/a;
				c=0;
				while(ans1>ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				if(c>0)fprintf(fp,"题目%d:%d %c %d = %d'%d/%d\n",y,num1,signal1,num2,c,num1,num2);
				if(c=0)fprintf(fp,"题目%d:%d %c %d = %d/%d\n",y,num1,signal1,num2,num1,num2);
			    fclose(fp);break;
		}
	}
	if(num==2)
	{
		if(signal2=='x'&&signal1!='/')
		{
			int ans1;
			ans1=num2*num3;
			switch(signal1)
		    {
		    	case '+':
		    		ans=num1+ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
		    	    fclose(fp);break;
		    	case '-':
		    		if(num1<ans1)question(y,r);
		    		else
		    		{
					    ans=num1-ans1;
		    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
		    	        fclose(fp);
					}break;
		    	case 'x':
		    		ans=num1*ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
		    	    fclose(fp);break;
		    }
		}
		else
		if(signal2=='/'&&signal1!='/')
		{
			int ans1,ans2;
			c=0;
			a=gcd(num2,num3);
			ans1=num2/a;
			ans2=num3/a;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(signal1)
		    {
		    	case '+':
		    		c=num1+c;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
		    	    fclose(fp);break;
		    	case '-':
		    		if(num1<=c)question(y,r);
		    		else
		    		{
		    	    	c=num1-c;
		        		int a1,a2;
		        		if(c=1)
		        		{
		        			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		    			else
		    			{
		    				c--;
			    			a1=ans2-ans1;
		        			a2=ans2;
		    			}
		        	}
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
		    	    fclose(fp);break;
		    	case 'x':
		    		int ans1;
		    		c=0;
					ans1=num1*num2;
		    		a=gcd(ans1,num3);
		    		ans1=ans1/a;
		    		ans2=num3/a;
		    		while(ans1>ans2)
		    		{
		    			ans1=ans1-ans2;
		    			c++;
					}
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
		    	    fclose(fp);break;
		    	case '/':
		    		c=0;
		    		ans2=num2*num3;
		    		a=gcd(num1,ans2);
		    		ans1=num1/a;
		    		ans2=ans2/a;
		    		while(ans1>ans2)
		    		{
		    			ans1=ans1-ans2;
		    			c++;
					}
		    		ans=num1/ans1;
		    	    fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
		    	    fclose(fp);break;
		    }
		}
	    if(signal1=='/')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(signal2)
	    	{
	    		case '+':
	    			a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					c=c+num3;
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
					fclose(fp);break;
				case '-':
					a=gcd(num1,num2);
	    			ans1=num1/a;
	    			ans2=num2/a;
	    			c=0;
	    			while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					if(c<num3) question(y,r);
					else 
					if(c=num3)
					{
						fprintf(fp,"题目%d:%d %c %d %c %d = %d/%d\n",y,num1,signal1,num2,signal2,num3,ans1,ans2);
						fclose(fp);
					}
					else
					if(c>num3)
					{
						c=c-num3;
						fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
						fclose(fp);
					}break;
				case 'x':
					ans1=num1*num3;
					a=gcd(ans1,num2);
					ans1=ans1/a;
					ans2=num2/a;
					c=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
					fclose(fp);break;
				case '/':
					ans2=num2*num3;
					a=gcd(num1,ans2);
					ans1=num1/a;
					ans2=ans2/a;
					c=0;
					while(ans1>ans2)
	    			{
	    				ans1=ans1-ans2;
	    				c++;
					}
					fprintf(fp,"题目%d:%d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,c,ans1,ans2);
					fclose(fp);break;
			}
		}
		else
		if(signal1='+')
	    {
	    	int ans1,ans2;
	    	c=0;
	    	switch(signal2)
    		{
	    		case '+':
	    			ans=num1+num2+num3;
	    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		    fclose(fp);break;
    			case '-':
    				if(num1+num2<num3)question(y,r);
    				else
    				{
    					ans=num1+num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
	    }
	    else
	    if(signal1='-')
	    {
	    	switch(signal2)
    		{
	    		case '+':
	    			if(num1-num2+num3<0)question(y,r);
	    			else
	    			{
	    				ans=num1-num2+num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		        fclose(fp);break;
					}	
    			case '-':
    				if(num1-num2-num3<0)question(y,r);
    				else
    				{
    					ans=num1-num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
		else
		if(signal1='x')
		{
			switch(signal2)
    		{
	    		case '+':
	    			ans=num1*num2+num3;
	    		    fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		    fclose(fp);break;
    			case '-':
    				if(num1*num2<num3)question(y,r);
    				else
    				{
    					ans=num1*num2-num3;
	    		        fprintf(fp,"题目%d:%d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,ans);
	    		        fclose(fp);break;
					}
	    	}
		}
	}
	if(num==3)
	{
		if(signal1=='x')
		{
			int ans1;
			ans1=num1*num2;
			if(signal3=='x'&&signal2!='/')
	    	{
		    	int ans2;
		    	ans2=num3*num4;
		    	switch(signal2)
		        {
		        	case '+':
		        		ans=ans1+ans2;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		        	    fclose(fp);break;
		        	case '-':
		        		if(ans1>ans2)question(y,r);
		        		else
		        		{
		        			ans=ans1-ans2;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		            	    fclose(fp);
					 	}break;
		        	case 'x':
	    	    		ans=ans1*ans2;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		         	    fclose(fp);break;
		        }
			}
	      	else
			if(signal3=='/'&&signal2!='/')
	      	{
	      		int ans2,ans3;
	      		c=0;
	      		switch(signal2)
		        {
		        	case '+':
		        		a=gcd(num3,num4);
		        		ans2=num3/a;
		        		ans3=num4/a;
		        		c=0;
		        		while(ans2>ans3)
		        		{
		        			ans2=ans2-ans3;
		        			c++;
						}
						c=c+ans1;
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans2,ans3);
		        	    fclose(fp);break;
		        	case '-':
		        		if(ans1<(num3/num4))question(y,r);
		        		else
		        		{
		        			a=gcd(num3,num4);
		        			ans2=num3/a;
		        			ans3=num4/a;
		        			c=0;
		        			while(ans2>ans3)
		        			{
		        				ans2=ans2-ans3;
		        				c++;
							}
							c=ans1-c-1;
							ans2=ans3-ans2;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans2,ans3);
		        	        fclose(fp);
						}break;
		        		
		        	case 'x':
	    	    		ans1=ans1*num3;
	    	    		a=gcd(ans1,num4);
	    	    		c=0;
	    	    		ans2=ans1/a;
	    	    		ans3=num4/a;
	    	    		while(ans2>ans3)
	    	    		{
	    	    			ans2=ans2-ans3;
	    	    			c++;
						}
		        	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans2,ans3);
		         	    fclose(fp);break;
		        }
			}
			else
			if(signal2=='/')
			{
				c=0;
				int ans2;
				a=gcd(ans1,num3);
				ans1=ans1/a;
				ans2=num3/a;
				while(ans1>ans2)
				{
					ans1=ans1-ans2;
					c++;
				}
				switch(signal3)
				{
					case '+':
						c=c+num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
					    fclose(fp);break;
					case '-':
						if(c<num4)question(y,r);
						else
						{
							c=c-num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
					        fclose(fp);
						}break;
					case 'x':
						ans1=num1*num2*num4;
						a=gcd(ans1,num3);
						c=0;
						ans1=ans1/a;
						ans2=num3/a;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
					    fclose(fp);break;
					case '/':
						ans2=num3*num4;
						a=gcd(ans1,ans2);
						c=0;
						ans1=ans1/a;
						ans2=ans2/a;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
						fclose(fp);break;
				}
			}
			else
			if(signal2=='x')
			{
				c=0;
				int ans2,ans;
				ans1=num1*num2*num3;
				switch(signal3)
				{
					case '+':
						ans=ans1+num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
						fclose(fp);break;
					case '-':
						if(ans1<num4)question(y,r);
						else
						{
							ans=ans1-num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
							fclose(fp);
						}break;
					case 'x':
						ans=ans1*num4;
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
						fclose(fp);break;
					case '/':
						a=gcd(ans1,num4);
						ans1=ans1/a;
						ans2=num4/a;
						while(ans1>ans2)
						{
							ans1=ans1-ans2;
							c++;
						}
						fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
						fclose(fp);break;
				}
			}
		    else
		    {
		    	int ans2;
		    	switch(signal2)
    	    	{
	        		case '+':
	        			ans2=ans1+num3;break;
        			case '-':
	        			ans2=ans1-num3;break;
	        		case 'x':
        				ans2=ans1*num3;break;
	        	}
			    switch(signal3)
        		{
	        		case '+':
	        			ans=ans2+num4;
	        		    fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	        		    fclose(fp);break;
        			case '-':
        				if(ans2<num4)question(y,r);
        				else
        				{
        					ans=ans2-num4;
	        		        fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	        		        fclose(fp);
						}break;
	        	}
			}
    	}
		else
		if(signal1=='/')
		{
			c=0;
			int ans1,ans2,ans3;
			switch(signal2)
			{
				case '+':
					a=gcd(num1,num2);
					ans1=num1/a;
					ans2=num2/a;
					c=0;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					switch(signal3)
					{
						case '+':
							ans3=num3+num4;
							c=c+ans3;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	ans3=num3-num4;
	        		    	if(ans<0&&c+ans3<0)question(y,r);
	        		    	else
	        		    	{
	        		    		c=c+ans3;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans3=num3*num4;
							c=c+ans3;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1*num4+num3*num2;
	        		    	ans2=num2*num4;
	        		    	a=gcd(ans1,ans2);
	        		    	c=0;
	        		    	ans1=ans1/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
	        		    	{
	        		    		ans1=ans1-ans2;
	        		    		c++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
					}break;
					break;
				case '-':
					a=gcd(num1,num2);
					c=0;
					ans1=num1/a;
					ans2=num2/a;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					switch(signal3)
					{
						case '+':
							ans3=num3-num4;
							if(c<ans3)question(y,r);
							else
							{
								c=c-ans3;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	ans3=num3+num4;
	        		    	if(c<ans3)question(y,r);
	        		    	else
	        		    	{
	        		    		c=c-ans3;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans3=num3*num4;
							if(c<ans3)question(y,r);
							else
							{
								c=c-ans3;
					    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case '/':
	        		    	ans1=num1*num4-num3*num2;
	        		    	ans2=num2*num4;
	        		    	a=gcd(ans1,ans2);
	        		    	c=0;
	        		    	ans1=ans1/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
	        		    	{
	        		    		ans1=ans1-ans2;
	        		    		c++;
							}
							if(ans1<0)question(y,r);
							else
							{
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
				    break;
				case 'x':
					ans1=num1*num3;
					a=gcd(ans1,num2);
					ans1=ans1/a;
					ans2=num2/a;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					switch(signal3)
					{
						case '+':
							c=c+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(c<num4)question(y,r);
	        		    	else
	        		    	{
	        		    		c=c-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num1*num3*num4;
							a=gcd(ans1,num2);
							ans1=ans1/a;
							ans2=num2/a;
							c=0;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1*num3;
	        		    	ans2=num2*num4;
	        		    	c=0;
	        		    	a=gcd(ans1,ans2);
	        		    	ans1=ans1/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
					}break;
				    break;
				case '/':
					ans2=num2*num3;
					a=gcd(num1,ans2);
					ans1=num1/a;
					ans2=ans2/a;
					c=0;
					while(ans1>ans2)
					{
						ans1=ans1-ans2;
						c++;
					}
					switch(signal3)
					{
						case '+':
							c=c+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(c<num4)question(y,r);
	        		    	else
	        		    	{
	        		    		c=c-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num1*num4;
							ans2=num2*num3;
							c=0;
							a=gcd(ans1,ans2);
							ans1=ans1/a;
							ans2=ans2/a;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans1=num1;
	        		    	ans2=num2*num3*num4;
	        		    	c=0;
	        		    	a=gcd(num1,ans2);
	        		    	ans1=num1/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
					}break;
			        break;
			}
		}
		else
		if(signal2=='x')
		{
			int ans1;
			c=0;
			ans1=num2*num3;
			switch(signal1)
	    	{
		    	int ans2;
		    	case '+':
		    		switch(signal3)
		            {
		            	case '+':
		        	    	ans=num1+ans1+num4;
		            	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		            	    fclose(fp);break;
		            	case '-':
		            		if(num1+ans1<num4)question(y,r);
		            		else
		            		{
		            			ans=num1+ans1-num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
	    	    	    	ans=num1+num4*ans1;
		            	    fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		             	    fclose(fp);break;
		        	    case '/':
		            		a=gcd(ans1,num4);
		            		c=0;
		            		ans1=ans1/a;
		            		ans2=num4/a;
		            		while(ans1>ans2)
		            		{
		            			ans1=ans1-ans2;
		            			c++;
							}
							c=c+num1;
		        	        fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	 	        	        fclose(fp);break;
		            }break;
		            break;
				case '-':
		        	switch(signal3)
		            {
		            	case '+':
		            		if(a+num4<ans1)question(y,r);
		            		else
		            		{
		            			ans=num1-ans1+num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		            	        fclose(fp);
							}break;
		            	case '-':
		            		if(num1<ans1+num4)question(y,r);
		            		else
		            		{
		            			ans=num1-ans1-num4;
		            			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		                	    fclose(fp);
							}break;
		             	case 'x':
		             		if(num1<ans1*num4)question(y,r);
		             		else
		             		{
		             			ans=num1-num4*ans1;
		             			fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
		             	        fclose(fp);
							}break;
		        	    case '/':
		            		a=gcd(ans1,num4);
		            		c=0;
		            		ans1=ans1/a;
		            		ans2=num4/a;
		            		while(ans1>ans2)
		            		{
		            			ans1=ans1-ans2;
		            			c++;
							}
							if(num1<=c)question(y,r);
							else
							{
								c=num1-c-1;
								ans1=ans2-ans1;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d = %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	 	        	            fclose(fp);
							}break;
		            }break;
			    break;
			}
		}
		else
		if(signal2=='/')
		{
			int ans1,ans2;
			c=0;
			a=gcd(num2,num3);
			ans1=num2/a;
			ans2=num3/a;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(signal1)
			{
				case'+':
					switch(signal3)
					{
						case '+':
							c=c+num1+num4;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(num1+c<num4)question(y,r);
	        		    	else
	        		    	{
	        		    		c=c+num1-num4;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);break;
							}
						case 'x':
							ans1=num2*num4;
							c=0;
							a=gcd(ans1,num3);
							ans1=ans1/a;
							ans2=ans2/a;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=c+num1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	c=0;
	        		    	a=gcd(num2,ans2);
	        		    	ans1=num2/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=c+num1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
					}break;
			        break;
				case '-':
					switch(signal3)
					{
						case '+':
							if(num1+num4<c)question(y,r);
							else
							{
								c=num1+num4-c-1;
								ans1=ans2-ans1;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<num4+c)question(y,r);
	        		    	else
	        		    	{
	        		    		c=num1-num4-c-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
						case 'x':
							ans1=num2*num4;
							c=0;
							a=gcd(ans1,num3);
							ans1=ans1/a;
							ans2=ans2/a;
							while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=num1-c-1;
							ans1=ans2-ans1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '/':
	        		    	ans2=num3*num4;
	        		    	c=0;
	        		    	a=gcd(num2,ans2);
	        		    	ans1=num2/a;
	        		    	ans2=ans2/a;
	        		    	while(ans1>ans2)
							{
								ans1=ans1-ans2;
								c++;
							}
							c=num1-c-1;
							ans1=ans2-ans1;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
					}break;
		            break;
			}
		}
		else
		if(signal3=='x')
		{
			int ans1;
			ans1=num3*num4;
			int ans2;
		    switch(signal1)
    	    {
	        	case '+':
	        		ans2=num1+num2;break;
        		case '-':
	        		ans2=num1-num2;break;
	        }
			switch(signal2)
        	{
	        	case '+':
	        		ans=ans1+ans2;
	        		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	        		fclose(fp);break;
        		case '-':
        			if(ans1<ans2)question(y,r);
        			else
        			{
        				ans=ans1-ans2;
        				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	        	        fclose(fp);
					}break;
	        }
		}
		else
		if(signal3=='/')
		{
			c=0;
			int ans1,ans2;
			a=gcd(num3,num4);
			ans1=num3/a;
			ans2=num4/a;
			while(ans1>ans2)
			{
				ans1=ans1-ans2;
				c++;
			}
			switch(signal1)
			{
				case '+':
					switch(signal2)
					{
						case '+':
							c=c+num1+num2;
							fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		        fclose(fp);break;
	        		    case '-':
	        		    	if(num1+num2<c)question(y,r);
	        		    	else
	        		    	{
	        		    		c=num1+num2-c-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
				case '-':
					switch(signal2)
					{
						case '+':
							if(num1+c<num2)question(y,r);
							else
							{
								c=num1+c-num2;
								fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
	        		    case '-':
	        		    	if(num1<c+num2)question(y,r);
	        		    	else
	        		    	{
	        		    		c=num1-num2-c-1;
	        		    		ans1=ans2-ans1;
	        		    		fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d'%d/%d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,c,ans1,ans2);
	        		            fclose(fp);
							}break;
					}break;
			}
		}
	    else
	    if(signal1=='+')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1+num2;
	    	if(signal2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(signal3=='+')
	    		{
	    			ans=ans2+num4;
	    			fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    			fclose(fp);
				}
				else
				if(signal3=='-')
	    		{
	    			if(ans2<num4)question(y,r);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(signal2=='-')
			{
				ans2=ans1-num3;
				if(signal3=='+')
	    		{
	    			if(ans2+num4<0)question(y,r);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(signal3=='-')
	    		{
	    			if(ans2-num4<0)question(y,r);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    				fclose(fp);
					}
				}
			}
    	}
    	else
	    if(signal1=='-')
	    {
	    	int ans1,ans2,ans;
	    	ans1=num1-num2;
	    	if(signal2=='+')
	    	{
	    		ans2=ans1+num3;
	    		if(signal3=='+')
	    		{
	    			if(ans2+num4<0)question(y,r);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(signal3=='-')
	    		{
	    			if(ans2<num4)question(y,r);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    				fclose(fp);
					}
				}
	    	}
	    	else
			if(signal2=='-')
			{
				ans2=ans1-num3;
				if(signal3=='+')
	    		{
	    			if(ans2+num4<0)question(y,r);
	    			else
	    			{
	    				ans=ans2+num4;
	    		    	fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    		    	fclose(fp);
					}
				}
				else
				if(signal3=='-')
	    		{
	    			if(ans2-num4<0)question(y,r);
	    			else
	    			{
	    				ans=ans2-num4;
	    				fprintf(fp,"题目%d:%d %c %d %c %d %c %d= %d\n",y,num1,signal1,num2,signal2,num3,signal3,num4,ans);
	    				fclose(fp);
					}
				}
			}
    	}
	    
	}
	return 0;
}
int question(int y,int r)//生成题目 
{
	FILE *fp;
	//srand((unsigned)time(0));
    int get;
    int num,num1,num2,num3,num4;
    char signal1,signal2,signal3;
    
    signal1=getSignal();
    signal2=getSignal();
    signal3=getSignal();
    num1=random(r);
    num2=random(r);
    num3=random(r);
    num4=random(r);
    num=rand()%3+1;
    
    //num=3,num1=3,num2=2,num3=3,num4=4,signal1='/',signal2='-',signal3='-';
    if(num==1)
    {
     	answers(y,num,num1,num2,num3,num4,signal1,signal2,signal3,r);
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"题目%d:%d %c %d = \n",y,num1,signal1,num2);
     	fclose(fp);
	}
	if(num==2)
	{
     	answers(y,num,num1,num2,num3,num4,signal1,signal2,signal3,r);
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"题目%d:%d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3);
     	fclose(fp);
		}
	if(num==3)
	{
     	answers(y,num,num1,num2,num3,num4,signal1,signal2,signal3,r);
     	fp=fopen("Exercises.txt","a");
     	fprintf(fp,"题目%d:%d %c %d %c %d %c %d = \n",y,num1,signal1,num2,signal2,num3,signal3,num4);
     	fclose(fp);
	}
	return 0;
} 
int main()
{
	srand((unsigned)time(0));
	FILE *fp;
	fp=fopen("Exercises.txt","w");
	fclose(fp);
	fp=fopen("Answers.txt","w");
	fclose(fp);
	int n,r;
	int y=1;
	char argv1[3];
    char argv2[3];
    //n=10,r=10;
    scanf("%s",argv1);//-n
	scanf("%d",&n);;
	scanf("%s",argv2);//-r
	scanf("%d",&r);
	if(!strcmp(argv1,"-n")&&!strcmp(argv2,"-r"))
	{
		while(n>0)
		{
			question(y,r);
			y++;
			n--;
		}
	}
	else printf("输入错误！");
	return 0;
}