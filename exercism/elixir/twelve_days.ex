defmodule TwelveDays do
  @doc """
  Given a `number`, return the song's verse for that specific day, including
  all gifts for previous days in the same line.
  """


  def number_to_day(number) do
    cond do
      number == 1 -> "first"
      number == 2 -> "second"
      number == 3 -> "third"
      number == 4 -> "fourth"
      number == 5 -> "fifth"
      number == 6 -> "sixth"
      number == 7 -> "seventh"
      number == 8 -> "eighth"
      number == 9 -> "ninth"
      number == 10 -> "tenth"
      number == 11 -> "eleventh"
      true         -> "twelfth"
    end
  end

  def number_object(number, acc, stop \\ 12) do
    cond do
      stop == 0 -> acc
      number == 1 -> acc <> "a Partridge in a Pear Tree"
      number == 2 -> number_object(number-1, acc <> "two Turtle Doves, and ", stop-1)
      number == 3 -> number_object(number-1, acc <> "three French Hens, ", stop-1)
      number == 4 -> number_object(number-1, acc <> "four Calling Birds, ", stop-1)
      number == 5 -> number_object(number-1, acc <> "five Gold Rings, ", stop-1)
      number == 6 -> number_object(number-1, acc <> "six Geese-a-Laying, ", stop-1)
      number == 7 -> number_object(number-1, acc <> "seven Swans-a-Swimming, ", stop-1)
      number == 8 -> number_object(number-1, acc <> "eight Maids-a-Milking, ", stop-1)
      number == 9 -> number_object(number-1, acc <> "nine Ladies Dancing, ", stop-1)
      number == 10 -> number_object(number-1, acc <> "ten Lords-a-Leaping, ", stop-1)
      number == 11 -> number_object(number-1, acc <> "eleven Pipers Piping, ", stop-1)
      true         -> number_object(number-1, acc <> "twelve Drummers Drumming, ", stop-1)
    end
  end

  @spec verse(number :: integer) :: String.t()
  def verse(number) do
    "On the #{number_to_day(number)} day of Christmas my true love gave to me: #{number_object(number, "")}."
  end

  @doc """
  Given a `starting_verse` and an `ending_verse`, return the verses for each
  included day, one per line.
  """
  @spec verses(starting_verse :: integer, ending_verse :: integer) :: String.t()
  def verses(starting_verse, ending_verse, acc \\ "") do
    cond do
      starting_verse == ending_verse + 1 -> acc
      starting_verse == ending_verse -> verses(starting_verse + 1, ending_verse, acc <> verse(starting_verse))
      true -> verses(starting_verse + 1, ending_verse, acc <> verse(starting_verse) <> "\n")
    end
  end

  @doc """
  Sing all 12 verses, in order, one verse per line.
  """
  @spec sing() :: String.t()
  def sing do
    verses(1,12)
  end
end
