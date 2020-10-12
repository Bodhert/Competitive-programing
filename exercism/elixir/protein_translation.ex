defmodule ProteinTranslation do
  @doc """
  Given an RNA string, return a list of proteins specified by codons, in order.
  """
  @spec of_rna(String.t()) :: {atom(), list(String.t())}
  def of_rna(rna), do: of_rna(rna, [])

  def of_rna(<<>>, acc) do
    {:ok,acc}
  end

  def of_rna(<< codon::binary-size(3), rest::binary >>, acc) do
    case of_codon(codon) do
      {:error, _ } -> {:error, "invalid RNA"}
      {:ok, "STOP"} -> {:ok, acc}
      {:ok, protein} -> of_rna(rest, acc ++ [protein])
    end
  end

  @doc """
  Given a codon, return the corresponding protein

  UGU -> Cysteine
  UGC -> Cysteine
  UUA -> Leucine
  UUG -> Leucine
  AUG -> Methionine
  UUU -> Phenylalanine
  UUC -> Phenylalanine
  UCU -> Serine
  UCC -> Serine
  UCA -> Serine
  UCG -> Serine
  UGG -> Tryptophan
  UAU -> Tyrosine
  UAC -> Tyrosine
  UAA -> STOP
  UAG -> STOP
  UGA -> STOP
  """
  @proteins %{
    "UGU" => "Cysteine",
    "UGC" => "Cysteine",
    "UUA" => "Leucine",
    "UUG" => "Leucine",
    "AUG" => "Methionine",
    "UUU" => "Phenylalanine",
    "UUC" => "Phenylalanine",
    "UCU" => "Serine",
    "UCC" => "Serine",
    "UCA" => "Serine",
    "UCG" => "Serine",
    "UGG" => "Tryptophan",
    "UAU" => "Tyrosine",
    "UAC" => "Tyrosine",
    "UAA" => "STOP",
    "UAG" => "STOP",
    "UGA" => "STOP",
  }

  @spec of_codon(String.t()) :: {atom, String.t()}
  def of_codon(codon)do
    case Map.fetch(@proteins,codon) do
      :error -> {:error, "invalid codon"}
      {:ok, codon} -> {:ok, codon}
    end
  end

end
