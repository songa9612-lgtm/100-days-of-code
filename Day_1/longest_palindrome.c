#include<stdio.h>
#include<string.h>

int expand(char *str,int left,int right,int len)//返回跳跃次数
{
    int count=0;
    while(left>=0&&right<len&&str[left]==str[right])
    {
        count++;//每次找到一个回文串，计数器加1
        left--;
        right++;
    }
    return count;
}

int main()
{
    int left=0,right=0,max=0,max_len=0;
    char str[1000];
    printf("请输入一个字符串: ");
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int odd=expand(str,i,i,len);//奇数长度回文
        int even=expand(str,i,i+1,len);//偶数长度回文
        int temp=odd>even?odd:even;//取两者较大值
        if (temp>max)
        {
            max=temp;
            left=i-temp+1;//更新最长回文串的起始位置和结束位置
            right=i+temp-1;
            max_len=right-left+1;//更新最长回文串的长度
        }
        
    }

    printf("最长回文串的起始位置: %d, 结束位置: %d, 长度: %d\n", left+1, right+1, max_len);
    for(int i=left;i<=right;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");


}



