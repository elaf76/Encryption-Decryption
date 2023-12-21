#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void scan_string(char*str)
{

    int i=0;
    scanf(" %c",&str[i]);

    for(;str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}
void print_string (char*str)
{
    for(int i=0;str[i];i++)
    {
        printf("%c",str[i]);
    }

}
int string_len(char*str)
{
    int i;
    for(i=0;str[i];i++);
    return i++;
}

int main() {
	char msg[100],cmsg[100],type,small='a',capital='A';
	int key,msg_size;
	printf("Enter 'E' For Encryption or 'D' For Decryption\n");
	scanf(" %c",&type);
	printf("\n********************\n");
    printf("\n");
	printf("enter message you want :\n");
	scan_string(&msg);
    printf("\n********************\n");
    printf("\n");

    printf("Your message: \n");
	print_string(&msg);
	printf("\n********************\n");
    printf("\n");

	printf("enter KEY  :");
	scanf("%d",&key);
    printf("\n********************\n");
    printf("\n");


    msg_size=string_len(&msg);

	if(key>=26){
		key-=26;
	}
	switch(type){
	case 'E':
		for(int i=0;msg[i];i++)
		{

			if(msg[i]==' '){
				cmsg[i]=msg[i];
			}
			else if (msg[i]!=' ')
            {
				if(msg[i]>='a'&&msg[i]<='z')
                {

                    if(msg[i]+key>'z')
                    {
                        cmsg[i]='a'+(key-1-('z'-msg[i]));
                    }
                    else
                    {
                        cmsg[i]=msg[i]+key;
                    }

                }
                else if(msg[i]>='A'&&msg[i]<='Z')
                {
                     if(msg[i]+key>'Z')
                    {
                        cmsg[i]='A'+(key-1-('Z'-msg[i]));
                    }
                    else
                    {
                        cmsg[i]=msg[i]+key;
                    }
                }
			}
		}

		break;
	case 'D':
		for(int i=0;i<msg[i];i++)
		{
			if(msg[i]==' '){
				cmsg[i]=msg[i];
			}
			else if (msg[i]!=' ')
            {
				if(msg[i]>='a'&&msg[i]<='z')
                {

                    if(msg[i]-key<'a')
                    {
                        cmsg[i]='z'-(key-1+('a'-msg[i]));
                    }
                    else
                    {
                        cmsg[i]=msg[i]-key;
                    }

                }
                else if(msg[i]>='A'&&msg[i]<='Z')
                {
                     if(msg[i]-key<'A')
                    {
                        cmsg[i]='Z'-(key-1+('A'-msg[i]));
                    }
                    else
                    {
                        cmsg[i]=msg[i]-key;
                    }
                }
			}
		}

		break;
	}
	for(int i=0;i<msg_size;i++)
			{
		printf("%c", msg[i]);
			}

       printf("\n");


	for(int i=0;i<msg_size;i++)
			{
		printf("%c", cmsg[i]);
			}
    printf("\n");

	return 0;
}
