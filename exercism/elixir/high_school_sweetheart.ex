defmodule HighSchoolSweetheart do
  use TypeCheck
  @spec! first_letter(String.t()) :: String.t()
  def first_letter(name) do
    name
    |> String.trim
    |> String.first
  end

  @spec! initial(String.t()) :: String.t()
  def initial(name) do
    initial = name
    |> first_letter
    |> String.capitalize

    "#{initial}."
  end

  @spec! initials(String.t()) :: String.t()
  def initials(full_name) do
    [first_name, last_name] = String.split(full_name, " " , parts: 2)
    "#{initial(first_name)} #{initial(last_name)}"
  end

  @spec! pair(String.t(), String.t()) :: String.t()
  def pair(full_name1, full_name2) do
    i1 = initials(full_name1)
    i2 = initials(full_name2)
    """
                    ******       ******
                  **      **   **      **
                **         ** **         **
               **            *            **
               **                         **
               **     #{i1}  +  #{i2}     **
                **                       **
                  **                   **
                    **               **
                      **           **
                        **       **
                          **   **
                            ***
                             *
               """
  end
end
