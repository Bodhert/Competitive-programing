defmodule Username do
  use TypeCheck

  @spec! sanitize(charlist) :: charlist
  def sanitize(username) do
    username
    |> List.foldl('',fn char, acc ->
      acc ++
      case char do
        ?ä -> 'ae'
        ?ö -> 'oe'
        ?ß -> 'ss'
        ?ü -> 'ue'
        _ when char >= ?a and char <= ?z or char == ?_-> [char]
        _ -> ''
      end
    end)
  end
end
