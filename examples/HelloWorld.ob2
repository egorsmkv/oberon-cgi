MODULE HelloWorld;

IMPORT io := Console;

BEGIN
  (* necessary CGI headers *)
  io.String("Content-Type: text/html");
  io.Ln;
  io.Ln;

  (* page content *)
  io.String("<p style='font-size: 20px; color: green'>Hello World!</p>");

  io.Ln;
END HelloWorld.
