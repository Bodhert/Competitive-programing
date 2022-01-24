defmodule DNA do

  @type nucleotide_encoded:: 0b0000 | 0b0001 | 0b0010 | 0b0100 | 0b1000
  @type nucleotide_decoded::  ?A | ?C | ?G | ?T | ?\s

  @spec encode_nucleotide(nucleotide_decoded()) :: nucleotide_encoded()
  def encode_nucleotide(?\s), do: 0b0000
  def encode_nucleotide(?A), do: 0b0001
  def encode_nucleotide(?C), do: 0b0010
  def encode_nucleotide(?G), do: 0b0100
  def encode_nucleotide(?T), do: 0b1000

  @spec decode_nucleotide(nucleotide_encoded())::nucleotide_decoded()
  def decode_nucleotide(0b0000), do: ?\s
  def decode_nucleotide(0b0001), do: ?A
  def decode_nucleotide(0b0010), do: ?C
  def decode_nucleotide(0b0100), do: ?G
  def decode_nucleotide(0b1000), do: ?T

  @spec encode(list(nucleotide_decoded())) :: bitstring()
  def encode(dna), do: do_encode(<<>>, dna)

  @spec do_encode(bitstring(), list(nucleotide_decoded())) :: bitstring()
  defp do_encode(acc, []), do: acc
  defp do_encode(acc, [nucleotide | rest]) do
    encoded = encode_nucleotide(nucleotide)
    new_encoded = <<acc::bitstring,  encoded::size(4)>>
    do_encode(new_encoded, rest)
  end

  @spec decode(bitstring()) :: list(nucleotide_decoded())
  def decode(dna) do
    do_decode([], dna)
  end

  @spec do_decode(list(nucleotide_decoded()), bitstring()) :: charlist()
  defp do_decode(acc,<<>>), do: acc
  defp do_decode(acc,<<nucleotide::size(4), rest::bitstring>>) do
    decoded = decode_nucleotide(nucleotide)
    new_decoded = acc ++ [decoded]
    do_decode(new_decoded, rest)
  end
end
