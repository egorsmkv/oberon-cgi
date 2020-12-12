MODULE ServerTime;

IMPORT io := Console, os := Platform;

BEGIN
  (* necessary CGI headers *)
  io.String("Content-Type: text/html");
  io.Ln;
  io.Ln;

  (* page content *)
  io.Int(os.Time(), 0);
  io.String(os.PathDelimiter);

  io.Ln;
END ServerTime.
