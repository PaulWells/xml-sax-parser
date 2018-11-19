#include "pch.h"
#include "CppUnitTest.h"

#include "../XmlSaxParser/XmlSaxParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace XmlSaxParserTests
{
    TEST_CLASS(XmlSaxParserTests)
    {
    public:

        TEST_METHOD(CreateXmlSaxParser)
        {
            std::unique_ptr<XmlSaxParser> parser = std::make_unique<XmlSaxParser>();
        }

    };
}