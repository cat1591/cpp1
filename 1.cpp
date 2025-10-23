// ### 题目描述
// 编写一个程序，用户输入一段英文句子，程序需要统计并输出以下信息： <br/>

// 句子中单词的总数。 <br/>
// 句子中最长单词及其长度。 <br/>
// 句子中每个单词的长度，并按照单词长度进行排序后输出。 <br/>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //1.单词的总数
    string sentence;
    cout<<"请输入一段英文句子"<<endl;
    cin>>sentence;
    int j=1;
    for(int i=0;i<sentence.length();i++)

    {
        while(sentence[i]==' ')
        {
            j+=1;
        }
        cout<<"单词的总数为"<<j<<endl;
        

    }
    //2.最长单词
    string longest ="";
    string current =""; 
    for (int i = 0; i <= sentence.length(); i++)
        {
            if (i == sentence.length() || sentence[i] ==' ')
            {
                if (current.length() > longest.length())
                {
                    //若当前单词长度大于之前的最长单词，则将最大值赋值为该单词
                    longest = current;
                }
                current = "";
            }     
            else 
            {
                current += sentence[i];//字符串连接
            }
        }
    cout<<"最长的单词为"<<longest<<endl;
    //3.每个单词长度，按序输出
    cout << "所有单词及其长度:" << endl;
    current = "";

    int k=0;
    int arr[j];
    
    for (int i = 0; i <= sentence.length(); i++) 
    {
        if (i == sentence.length() || sentence[i] == ' ') 
        {
            if (current!="") 
            {
                for(int m=0;m<j;m++)
                {
                    arr[m]=current.length();
                }
        
            }
            current = "";
        } 
        else 
        {
            current += sentence[i];
        }
        // 按单词长度排序（简单的冒泡排序）
        for (int i = 0; i < wordCount - 1; i++) 
        {
            for (int j = 0; j < wordCount - 1 - i; j++) 
            {
                if (words[j].length() > words[j + 1].length())
                {   
                    // 交换单词位置
                    string temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                }
            }
    }



}

