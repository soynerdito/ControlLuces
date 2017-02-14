
#ifndef hml_body
#define html_body

String HTML_BODY=
"<!DOCTYPE html>"
"<html>"
"<head>"
"<style>"
".button {"
"    background-color: #4CAF50;"
"    border: none;"
"    color: white;"
"    padding: 50px 90px;"
"    text-align: center;"
"    text-decoration: none;"
"    display: inline-block;"
"    font-size: 48px;"
"    margin: 4px 2px;"
"    cursor: pointer;"
"}"
".button.red {"
"    background-color: #ff4d4d;"
"}"
"</style>"
"</head>"
"<body>"
"<div style=\"width: 100%; height: 20px; border-bottom: 1px solid blue; text-align: center\">"
"<span style=\"font-size: 40px; background-color: #FFFFFF; padding: 0 10px;\">"
"Piedra Control Page"
"</span>"
"</div>"
"<div style=\"width: 100%; height:50px; \">"
"</div>"
"<CENTER>"
"<a href=\"socket1On\">"
"<button class=\"button\">ON</button>"
"</a>&nbsp;<br><br><br>"
"<a href=\"socket1Off\">"
"<button class=\"button red\">OFF</button>"
"</a></CENTER>&nbsp;";

String  HTML_END =
"</body>"
"</html>";
#endif
