#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    cout << "请输入一段英文句子: ";
    getline(cin, sentence);  // 使用getline读取整行，包括空格
    
    // 1. 单词的总数
    int j = 0;  // 从0开始计数
    string current = "";
    
    // 先统计单词总数
    for(int i = 0; i <= sentence.length(); i++)
    {
        if(i == sentence.length() || sentence[i] == ' ')
        {
            if(current != "")  // 确保不是空单词
            {
                j++;  // 单词计数
                current = "";
            }
        }
        else
        {
            current += sentence[i];
        }
    }
    cout << "单词的总数为: " << j << endl;

    // 2. 最长单词
    string longest = "";
    current = ""; 
    for (int i = 0; i <= sentence.length(); i++)
    {
        if (i == sentence.length() || sentence[i] == ' ')
        {
            if (current.length() > longest.length())
            {
                longest = current;
            }
            current = "";
        }     
        else 
        {
            current += sentence[i];
        }
    }
    cout << "最长的单词为: " << longest << "，长度: " << longest.length() << endl;

    // 3. 每个单词长度，按序输出
    // 创建数组存储单词和长度
    string words[j];
    int lengths[j];
    int index = 0;
    current = "";
    
    // 提取所有单词
    for (int i = 0; i <= sentence.length(); i++) 
    {
        if (i == sentence.length() || sentence[i] == ' ') 
        {
            if (current != "") 
            {
                words[index] = current;
                lengths[index] = current.length();
                index++;
            }
            current = "";
        } 
        else 
        {
            current += sentence[i];
        }
    }
    
    // 按单词长度排序（冒泡排序）
    for (int i = 0; i < j - 1; i++) 
    {
        for (int k = 0; k < j - 1 - i; k++) 
        {
            if (lengths[k] > lengths[k + 1])
            {   
                // 交换长度
                int tempLen = lengths[k];
                lengths[k] = lengths[k + 1];
                lengths[k + 1] = tempLen;
                
                // 交换单词
                string tempWord = words[k];
                words[k] = words[k + 1];
                words[k + 1] = tempWord;
            }
        }
    }
    
    // 输出排序后的结果
    cout << "所有单词按长度排序:" << endl;
    for (int i = 0; i < j; i++) 
    {
        cout << words[i] << " - 长度: " << lengths[i] << endl;
    }

    return 0;
}