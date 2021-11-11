defmodule LogLevel do
  @spec to_label(integer, boolean) :: atom
  def to_label(0, false), do: :trace
  def to_label(1, _legacy?), do: :debug
  def to_label(2, _legacy?), do: :info
  def to_label(3, _legacy), do: :warning
  def to_label(4, _legacy?), do: :error
  def to_label(5, false), do: :fatal
  def to_label(_, _), do: :unknown

  @spec alert_recipient(integer, boolean) :: atom
  def alert_recipient(level, legacy?), do: call_alert(to_label(level, legacy?), legacy?)

  @spec call_alert(atom, boolean) :: atom
  defp call_alert(:unknown, true), do: :dev1
  defp call_alert(:unknown, false), do: :dev2
  defp call_alert(:error, _legacy?), do: :ops
  defp call_alert(:fatal, _legacy?), do: :ops
  defp call_alert(_level, _legacy?), do: false


end
