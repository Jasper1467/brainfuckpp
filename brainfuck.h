#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <string>
#include <vector>
#include <iostream>

class CBrainfuckInterpreter
{
public:
    CBrainfuckInterpreter(std::string szCode) : m_szCode(szCode), m_vecData(30000, 0), m_nPtr(0) {}

    void Interpret()
    {
        size_t pc = 0;
        size_t nCodeSize = m_szCode.size();

        while (pc < nCodeSize)
        {
            switch (m_szCode[pc])
            {
            case '>':
                ++m_nPtr;
                break;
            case '<':
                --m_nPtr;
                break;
            case '+':
                ++m_vecData[m_nPtr];
                break;
            case '-':
                --m_vecData[m_nPtr];
                break;
            case '.':
                std::cout << static_cast<char>(m_vecData[m_nPtr]);
                break;
            case ',':
                char input;
                std::cin >> input;
                m_vecData[m_nPtr] = input;
                break;
            case '[':
                if (m_vecData[m_nPtr] == 0)
                {
                    int nLoopCount = 1;
                    while (nLoopCount > 0)
                    {
                        ++pc;
                        if (m_szCode[pc] == '[')
                            ++nLoopCount;
                        else if (m_szCode[pc] == ']')

                            --nLoopCount;
                    }
                }
                break;
            case ']':
                if (m_vecData[m_nPtr] != 0)
                {
                    int nLoopCount = 1;
                    while (nLoopCount > 0)
                    {
                        --pc;
                        if (m_szCode[pc] == ']')
                            ++nLoopCount;
                        else if (m_szCode[pc] == '[')
                            --nLoopCount;
                    }
                }
                break;
            default:
                // Ignore any other characters
                break;
            }

            ++pc;
        }
    }

private:
    std::string m_szCode;
    std::vector<int> m_vecData;
    size_t m_nPtr;
};

#endif