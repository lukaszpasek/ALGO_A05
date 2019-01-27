#include <iostream>

using namespace std;

int part(int angle)
{
    if(angle%180==0)return 0;
    if(angle<180) return 1;
    return -1;
}

int line(int angle)
{
    if(angle==0) return 2;
    else if(angle==180) return -2;
    else if(angle==60 || angle==300)return 1;
    else if(angle==120 || angle==240) return -1;
}


int main()
{
    int angle=0,t,n;
    int x=0,y=0,movement=0;
    char sign;
    cin>>t;
    for(int i=0 ; i<t ; i++)
    {
        cin>>n;
        for(int i=0 ; i<n ; i++)
        {
            cin>>sign>>movement;

            switch(sign)
            {
            case 'L' :
                angle-=movement;
                if(angle<0) movement+=360;

                break;
            case 'R' :
                angle+=movement;
                if(angle>=360) angle-=360;

                break;
            case 'F' :
                if(angle==0) y+=movement*2;
                else if(angle==60)
                {
                    y+=movement;
                    x+=movement;
                }
                else if(angle==180)
                {
                    y-=movement*2;
                }
                else if(angle==120)
                {
                    x+=movement;
                    y-=movement;
                }
                else if(angle==240)
                {
                    y-=movement;
                    x-=movement;
                }
                else if(angle==300)
                {
                    y+=movement;
                    x-=movement;
                }

                break;
            case 'B' :
                if(angle==0) y-=movement*2;
                else if(angle==60)
                {
                    y-=movement;
                    x-=movement;
                }
                else if(angle==180)
                {
                    y+=movement*2;
                }
                else if(angle==120)
                {
                    y+=movement;
                    x-=movement;
                }
                else if(angle==240)
                {
                    y+=movement;
                    x+=movement;
                }
                else if(angle==300)
                {
                    x+=movement;
                    y-=movement;
                }

                break;

            default :
                break;

            }
        }
        //Process instructions
        if(angle==180|| angle==0)
        {
            if(x==0)
            {
                int movementY=y/2;
                int moves=0;

                if(angle==180) moves++;

                if(y!=0)moves++;

                cout<<moves<<endl;

                if(movementY <0) cout<<"B "<<-movementY<<" ";
                else if(movementY >0) cout<<"F "<<movementY<<" ";
                if(angle==180) cout<<"R 180";
                cout<<endl;
            }
            else
            {
                int movementY=0;
                int movementX=x;
                int angle1;
                if(x==y && x>0) angle1=60;
                else if(x==-y && x>0) angle1=120;
                else if(x==y && x<0) angle1=240;
                else if(x==-y && x<0) angle1=300;
                else if(y!=x)
                {
                    angle1=60;
                    movementY=y-movementX;
                    movementY/=2;
                }
                if(movementY==0)
                {
                    cout<<"3 "<<endl;
                }
                else
                {
                    cout<<"4 "<<endl;
                    if(movementY <0) cout<<"B "<<-movementY<<" ";
                    else if(movementY >0) cout<<"F "<<movementY<<" ";
                }
                cout<<"R "<<angle1<<" ";
                if(movementX >0) cout<<"F "<<movementX<<" ";
                else if(movementX <0) cout<<"B "<<-movementX<<" ";
                if(angle-angle1<0) cout<<"L "<<angle1-angle;
                else cout<<"R "<<angle-angle1;
                cout<<endl;
            }
        }
        else
        {
            int movementX =x/part(angle);
            int movementY=y -(line(angle)*movementX);
            int moves=1;
            movementY/=2;
            if(movementY !=0)moves++;
            if(movementX !=0)moves++;
            cout<<moves<<endl;
            if(movementY >0) cout<<"F "<<movementY<<" ";
            else  if(movementY <0) cout<<"B "<<-movementY<<" ";
            cout<<"R "<<angle<<" ";
            if(movementX >0) cout<<"F "<<movementX<<" ";
            else if(movementX <0) cout<<"B "<<-movementX<<" ";
            cout<<endl;
        }
        angle=0;
        movement=0;
        x=0;
        y=0;
    }

    return 0;
}
