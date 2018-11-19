#include "pch.h"
#include "CppUnitTest.h"

#include "../XmlSaxParser/XmlSaxParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace XmlSaxParserTests
{
    TEST_CLASS(XmlSaxParserTests)
    {
    public:

        TEST_METHOD(Constructor_WhenEventHandlerIsNotCallable_ThrowsArgumentException)
        {
            std::function<void(void)> eventHandler;
            Assert::ExpectException<std::invalid_argument>(
                [&eventHandler]() { XmlSaxParser parser(eventHandler); }
            );
        }

        TEST_METHOD(Parse_WhenXmlIsEmpty_ThrowsInvalidArgumentException)
        {
            std::function<void(void)> eventHandler = []() { return; };
            XmlSaxParser parser(eventHandler);
            std::string xml;
            Assert::ExpectException<std::invalid_argument>([&parser, &xml]() { parser.Parse(xml); });
        }

        TEST_METHOD(Parse_WhenXmlContainsCorrectProlog_NoExceptionIsThrown)
        {
            std::function<void(void)> eventHandler = []() { return; };;
            XmlSaxParser parser(eventHandler);

            std::string xml = R"(<?xml version="1.0"?>")";
            parser.Parse(xml);
        }

        // TODO: Add invalid prolog tests

    };
}