A SAX-style XML parser. This parser has several restrictions for simplicity of implementation:

 - It only supports XML version 1 and UTF-8. The version attribute must be present in the prolog of each XML document and no other attribute may be specified.

 - It does not support comments.