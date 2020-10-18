defmodule PigLatin do
  @doc """
  Given a `phrase`, translate it a word at a time to Pig Latin.

  Words beginning with consonants should have the consonant moved to the end of
  the word, followed by "ay".

  Words beginning with vowels (aeiou) should have "ay" added to the end of the
  word.

  Some groups of letters are treated like consonants, including "ch", "qu",
  "squ", "th", "thr", and "sch".

  Some groups are treated like vowels, including "yt" and "xr".
  """

  # cond do for the rest of the problem, and create more methods

  @spec translate(phrase :: String.t()) :: String.t()
  def translate(words) do
    String.split(words, " ") |>
    Enum.map(fn word -> pig_latin_conversion(word) end) |>
    Enum.join(" ")
  end

  @spec pig_latin_conversion(String.t()) :: String.t()
  def pig_latin_conversion(word) do
    cond do
      String.match?(word, ~r{^[aeiou]|x[b-df-hj-np-tv-z]|y[b-df-hj-np-tv-z]}) ->
        convert_vowel_sound(word)
      String.match?(word, ~r{^[b-df-hj-np-tv-z]?qu}) -> qu_start_with(word)
      String.match?(word, ~r{^[b-df-hj-np-tv-z]+}) -> convert_vocal(word)

    end
  end

  @spec convert_vocal(String.t()) :: String.t()
  def convert_vocal(word) do
    String.split(word, ~r{^[b-df-hj-np-tv-z]+}, include_captures: true, trim: true, parts: 2) |>
    Enum.reverse |>
    Enum.concat(["ay"]) |>
    Enum.join("")
  end

  @spec convert_vowel_sound(String.t()) :: String.t()
  def convert_vowel_sound(word) do
    word <> "ay"
  end

  def qu_start_with(<<first::binary-size(1), second::binary-size(1), third::binary-size(1), suffix::binary>>) do
    if first != "q" do
     suffix <> first <> second <> third <> "ay"
    else
     third <> suffix <> first <> second <> "ay"
    end
  end

end
