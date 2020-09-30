defmodule SecretHandshake do
  use Bitwise
  @doc """
  Determine the actions of a secret handshake based on the binary
  representation of the given `code`.

  If the following bits are set, include the corresponding action in your list
  of commands, in order from lowest to highest.

  1 = wink
  10 = double blink
  100 = close your eyes
  1000 = jump

  10000 = Reverse the order of the operations in the secret handshake
  """
  @spec commands(code :: integer) :: list(String.t())
  def commands(code) do
     [ wink(code &&& 1), double_blink(code &&& 2), close_your_eyes(code &&& 4),
       jump(code &&& 8 ) ]
      |> bitwise_reverse(code &&& 16)
      |> Enum.filter(fn str -> str != "" end)
  end

  @spec wink(integer) :: String.t()
  def wink(1) do
    "wink"
  end
  def wink(_) do
    ""
  end

  @spec double_blink(integer) :: String.t()
  def double_blink(2) do
    "double blink"
  end
  def double_blink(_) do
    ""
  end

  @spec close_your_eyes(integer) :: String.t()
  def close_your_eyes(4) do
    "close your eyes"
  end
  def close_your_eyes(_) do
    ""
  end

  @spec jump(integer) :: String.t()
  def jump(8) do
    "jump"
  end
  def jump(_) do
    ""
  end

  @spec bitwise_reverse(list(String.t()), integer()) :: list(String.t())
  def bitwise_reverse(list,16) do
   Enum.reverse(list)
  end
  def bitwise_reverse(list, _) do
   list
  end

end
