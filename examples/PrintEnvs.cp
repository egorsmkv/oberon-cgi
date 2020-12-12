MODULE PrintEnvs;

IMPORT Platform, io := Console;

VAR
  serverName, requestMethod, requestURI, queryString, pathInfo, scriptName,
  scriptFileName, serverPort, remoteAddr, remoteHost, remotePort: ARRAY 1024 OF SHORTCHAR;

PROCEDURE info(IN envName, envValue: ARRAY OF SHORTCHAR);
BEGIN
  io.String(envName);
  io.String("=");

  IF envValue # "" THEN
    io.String(envValue);
  ELSE
    io.String("this env is empty");
  END;

  io.Ln;
  io.String("<br>");
  io.Ln;
END info;

BEGIN
  (* necessary CGI headers *)
  io.String("Content-Type: text/html");
  io.Ln;
  io.Ln;

  (* get environment variables *)
  Platform.GetEnv("SERVER_NAME", serverName);
  Platform.GetEnv("REQUEST_METHOD", requestMethod);
  Platform.GetEnv("REQUEST_URI", requestURI);
  Platform.GetEnv("QUERY_STRING", queryString);
  Platform.GetEnv("PATH_INFO", pathInfo);
  Platform.GetEnv("SCRIPT_NAME", scriptName);
  Platform.GetEnv("SCRIPT_FILENAME", scriptFileName);
  Platform.GetEnv("SCRIPT_PORT", serverPort);
  Platform.GetEnv("REMOTE_ADDR", remoteAddr);
  Platform.GetEnv("REMOTE_HOST", remoteHost);
  Platform.GetEnv("REMOTE_PORT", remotePort);

  (* print environment variables to the browser *)
  info("SERVER_NAME", serverName);
  info("REQUEST_METHOD", requestMethod);
  info("REQUEST_URI", requestURI);
  info("QUERY_STRING", queryString);
  info("PATH_INFO", pathInfo);
  info("SCRIPT_NAME", scriptName);
  info("SCRIPT_FILENAME", scriptFileName);
  info("SCRIPT_PORT", serverPort);
  info("REMOTE_ADDR", remoteAddr);
  info("REMOTE_HOST", remoteHost);
  info("REMOTE_PORT", remotePort);

  io.Ln;
END PrintEnvs.
