#include "pch.h"
#include "XmlSaxParser.h"

XmlSaxParser::XmlSaxParser(std::function<void(void)> eventHandler)
    : m_EventHandler(eventHandler)
    , m_Index(0)
{
    if (!eventHandler)
    {
        throw std::invalid_argument("event handler must be callable");
    }
}

void XmlSaxParser::Parse(const std::string& xml)
{
    if (xml.empty())
    {
        throw std::invalid_argument("xml cannot be empty");
    }

    ParseProlog(xml);
}

void XmlSaxParser::ParseProlog(const std::string& xml)
{
    SkipWhitespace(xml);
    Require(xml, "<?xml");
    SkipWhitespace(xml);
    Require(xml, "version");
    SkipWhitespace(xml);
    Require(xml, "=");
    SkipWhitespace(xml);
    Require(xml, R"("1.0")");
    SkipWhitespace(xml);
    Require(xml, "?>");
}

void XmlSaxParser::Require(
    const std::string& xml,
    const std::string& required)
{
    for (char c : required)
    {
        if (xml[m_Index] != c)
        {
            throw std::invalid_argument("Invalid XML");
        }
        
        m_Index++;
    }
}

void XmlSaxParser::SkipWhitespace(const std::string& xml)
{
    while(IsWhitespace(xml[m_Index]) && m_Index < xml.size())
    {
        m_Index++;
    }
}

bool XmlSaxParser::IsWhitespace(char c)
{
    return c == ' ';
}