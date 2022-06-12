defmodule Newsletter do
  def read_emails(path) do
    path
    |> File.read!()
    |> String.split()
  end

  def open_log(path) do
    File.open!(path, [:write])
  end

  def log_sent_email(pid, email) do
    IO.puts(pid, email)
  end

  def close_log(pid) do
    File.close(pid)
  end

  def send_newsletter(emails_path, log_path, send_fun) do
    email_addresses = read_emails(emails_path)
    pid = open_log(log_path)

    Enum.each(email_addresses, fn mail ->
      with :ok <- send_fun.(mail) do
        log_sent_email(pid, mail)
      end
    end)

    close_log(pid)
  end
end
