defmodule RomanNumerals do
  @doc """
  Convert the number to a roman number.
  """
  @spec numeral(pos_integer) :: String.t()
  def numeral(number) do
    uni = ["", "I", "II", "III", "IV", "V","VI", "VII", "VIII", "IX"]
    deci = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    cen = ["", "C", "CC", "CCC", "CD", "D","DC", "DCC", "DCCC", "CM"]
    mil = ["", "M", "MM", "MMM"]
    IO.puts(number / 10)
    {_,nuni} = Enum.fetch(uni,number |> rem 10)
    {_,ndec} = Enum.fetch(deci,(div(number,10) |> rem 10))
    {_,ncen} = Enum.fetch(cen, div((div(number, 10)),10) |> rem 10 )
    {_,nmil} = Enum.fetch(mil,  div(div((div(number, 10)),10),10)|> rem 10)
    "#{nmil}#{ncen}#{ndec}#{nuni}"
  end
end
