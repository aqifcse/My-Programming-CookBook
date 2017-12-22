/**
** What is CGI?
** The Common Gateway Interface, or CGI,
is a set of standards that define how information is
exchanged between the web server and a custom script.
** when we click a hyperlink to browse a particular web page or URL.
** Your browser contacts the HTTP web server and demand for the URL ie. filename.
** Web Server will parse the URL and will look for the filename. If it finds requested file then web server sends that file
back to the browser otherwise sends an error message indicating that you have requested a wrong file.
** Web browser takes response from web server and displays either the received file or error message based on
the received response.
** it is possible to set up the HTTP server in such a way that whenever a file in a
certain directory is requested, that file is not sent back; instead it is executed as a program,
and produced output from the program is sent back to your browser to display.
**/

/**
** Web Server Configuration
** make sure that your Web Server supports CGI and it is configured to handle CGI Programs.
** All the CGI Programs to be executed by the HTTP server are kept in a pre-configured directory.
** This directory is called CGI directory and by convention it is named as /var/www/cgi-bin.
** By convention CGI files will have extension as .cgi, though they are C++ executable.
** By default, Apache Web Server is configured to run CGI programs in /var/www/cgi-bin.
** If you want to specify any other directory to run your CGI scripts, you can modify the
following section in the httpd.conf file −

<Directory "/var/www/cgi-bin">
   AllowOverride None
   Options ExecCGI
   Order allow,deny
   Allow from all
</Directory>

<Directory "/var/www/cgi-bin">
   Options All
</Directory>
**/

/** first code of CGI **/
/**
#include <iostream>
using namespace std;

int main () {
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Hello World - First CGI Program</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h2>Hello World! This is my first CGI program</h2>\n";
   cout << "</body>\n";
   cout << "</html>\n";

   return 0;
}
**/

/**
#include <iostream>
#include <stdlib.h>
using namespace std;

const string ENV[ 24 ] = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
   "SERVER_SIGNATURE","SERVER_SOFTWARE" };

int main () {
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>CGI Environment Variables</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<table border = \"0\" cellspacing = \"2\">";

   for ( int i = 0; i < 24; i++ ) {
      cout << "<tr><td>" << ENV[ i ] << "</td><td>";

      // attempt to retrieve value of environment variable
      char *value = getenv( ENV[ i ].c_str() );
      if ( value != 0 ) {
         cout << value;
      } else {
         cout << "Environment variable does not exist.";
      }
      cout << "</td></tr>\n";
   }

   cout << "</table><\n";
   cout << "</body>\n";
   cout << "</html>\n";

   return 0;
}
**/
/**
First CGI program
The above C++ program is a simple program which is writing its output on STDOUT file i.e. screen.
There is one important and extra feature available which is first line printing Content-type:text/html\r\n\r\n.
This line is sent back to the browser and specify the content type to be displayed on the browser screen.
Now you must have understood the basic concept of CGI and you can write many complicated CGI programs using Python.
A C++ CGI program can interact with any other external system, such as RDBMS, to exchange information.
HTTP Header
The line Content-type:text/html\r\n\r\n is a part of HTTP header, which is sent to the browser to understand the content.
All the HTTP header will be in the following form −
HTTP Field Name: Field Content

For Example
Content-type: text/html\r\n\r\n
There are few other important HTTP headers, which you will use frequently in your CGI Programming.
Sr.No
Header & Description
1
Content-type:
A MIME string defining the format of the file being returned. Example is Content-type:text/html.
2
Expires: Date
The date the information becomes invalid. This should be used by the browser to decide when a page needs to be refreshed.
A valid date string should be in the format 01 Jan 1998 12:00:00 GMT.
3
Location: URL
The URL that should be returned instead of the URL requested. You can use this filed to redirect a request to any file.
4
Last-modified: Date
The date of last modification of the resource.
5
Content-length: N
The length, in bytes, of the data being returned. The browser uses this value to report the estimated download time for a file.
6
Set-Cookie: String
Set the cookie passed through the string.
CGI Environment Variables
All the CGI program will have access to the following environment variables. These variables play an important role while
writing any CGI program.
Sr.No
Variable Name & Description
1
CONTENT_TYPE
The data type of the content, used when the client is sending attached content to the server. For example file upload etc.
2
CONTENT_LENGTH
The length of the query information that is available only for POST requests.
3
HTTP_COOKIE
Returns the set cookies in the form of key & value pair.
4
HTTP_USER_AGENT
The User-Agent request-header field contains information about the user agent originating the request. It is a name of the web browser.
5
PATH_INFO
The path for the CGI script.
6
QUERY_STRING
The URL-encoded information that is sent with GET method request.
7
REMOTE_ADDR
The IP address of the remote host making the request. This can be useful for logging or for authentication purpose.
8
REMOTE_HOST
The fully qualified name of the host making the request. If this information is not available then REMOTE_ADDR can be used to get IR address.
9
REQUEST_METHOD
The method used to make the request. The most common methods are GET and POST.
10
SCRIPT_FILENAME
The full path to the CGI script.
11
SCRIPT_NAME
The name of the CGI script.
12
SERVER_NAME
The server's hostname or IP Address.
13
SERVER_SOFTWARE
The name and version of the software the server is running.
**/
/**
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

int main () {
   Cgicc formData;

   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Using GET and POST Methods</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";

   form_iterator fi = formData.getElement("first_name");
   if( !fi->isEmpty() && fi != (*formData).end()) {
      cout << "First name: " << **fi << endl;
   } else {
      cout << "No text entered for first name" << endl;
   }

   cout << "<br/>\n";
   fi = formData.getElement("last_name");
   if( !fi->isEmpty() &&fi != (*formData).end()) {
      cout << "Last name: " << **fi << endl;
   } else {
      cout << "No text entered for last name" << endl;
   }

   cout << "<br/>\n";
   cout << "</body>\n";
   cout << "</html>\n";

   return 0;
}
**/

