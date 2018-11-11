#include "main.h"

void append_HTML_header()
{
  webpage  = "";
  webpage += "<!DOCTYPE html><html><head>";
  webpage += "<meta http-equiv='refresh' content='300'>"; // 5-min refresh time, test needed to prevent auto updates repeating some commands
  webpage += "<style>";
  webpage += "body {width:" + String(sitewidth) + "px;margin:0 auto;font-family:arial;font-size:14px;text-align:center;color:blue;background-color:#F7F2Fd;}";
  webpage += "h1 {background-color:#ffc66e;margin:16px 30px;}"; // Orange background
  webpage += "h3 {color:#9370DB;font-size:24px;width:auto;}";
  webpage += ".navbar{overflow:hidden;background-color:#558ED5;position:fixed;top:0;width:" + String(sitewidth) + "px;margin-left:30px;}";
  webpage += ".navbar a {float:left;display:block;color:yellow;text-align:center;padding:10px 12px;text-decoration: none;font-size:17px;}";
  webpage += ".main{padding:0px;margin:16px 30px;height:1000px;width:" + String(sitewidth) + "px;}";
  webpage += ".style1{text-align:center;font-size:16px;background-color:#FFE4B5;}";
  webpage += ".style2{text-align:left;font-size:16px;background-color:#F7F2Fd;width:auto;margin:0 auto;}";
  // Note: You cannot include (table, tr, td, or th) styles if you want Google Charts to work!
  webpage += "</style>";
  webpage += "</head><body>";
  webpage += "<div class='navbar'>";
  // For each new page you add or remove, make sure there is a menu item to call it or remove it when not used
  webpage += " <a href='/'>Home</a>";
  webpage += " <a href='/aps'>AP Scan List</a>";// SPP
  webpage += "</div>";
  webpage += "<br><title>" + sitetitle + "</title><br>";
  webpage += "<div class='main'><h1>" + siteheading + " " + siteversion + "</h1>";
}

void append_short_HTML_header()
{ // Needed because Google Charts appears to limit the amount of data that can be sent to its server
  webpage  = "";
  webpage += "<!DOCTYPE html><html><head>";
  webpage += "<style>";
  webpage += "body {width:" + String(sitewidth) + "px;margin:0 auto;font-family:arial;font-size:14px;text-align:center;color:blue;background-color:#F7F2Fd;}";
  webpage += "h1 {background-color:#d8d8d8;margin:16px 30px;}";
  webpage += "h3 {color:#9370DB;font-size:24px;width:auto;}";
  webpage += ".navbar{overflow:hidden;background-color:#558ED5;position:fixed;top:0;width:" + String(sitewidth) + "px;margin-left:30px;}";
  webpage += ".navbar a {float:left;display:block;color:yellow;text-align:center;padding:14px 16px;text-decoration: none;font-size:17px;}";
  webpage += ".main{padding:0px;margin:16px 30px;height:1000px;width:" + String(sitewidth) + "px;}";
  webpage += ".style1{text-align:center;font-size:16px;background-color:#FFE4B5;}";
  webpage += ".style2{text-align:left;font-size:16px;background-color:#F7F2Fd;width:auto;margin:0 auto;}";
  // Note: You cannot include table, tr, td, or th styles if you want Google Charts to work!
  webpage += "</style></head>";
  webpage += "<body>";
  webpage += "<div class='navbar'>";
  webpage += " <a href='/'>Home</a>";
  webpage += "</div>";
  webpage += "<title>" + sitetitle + "</title>";
  webpage += "<div class='main'>";
}

void append_HTML_footer()
{
  webpage += "<footer><p>" + yourfootnote + "<br>";
  webpage += "</p></footer>";
  webpage += "</div></body></html>";
}
