#pragma once

class XmlSaxParser
{
public:
    XmlSaxParser(std::function<void(void)> eventHandler);

    void Parse(const std::string& xml);
private:

    void ParseProlog(const std::string& xml);
    void Require(const std::string& xml, const std::string& required);
    void SkipWhitespace(const std::string& xml);
    bool IsWhitespace(char c);

    std::function<void(void)> m_EventHandler;
    int m_Index;

};

