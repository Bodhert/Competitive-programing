defmodule HighScore do
  use TypeCheck

  @default_score  0
  @spec! new :: %{}
  def new() do
    %{}
  end


  @spec! add_player(map, String.t(), number) :: map
  def add_player(scores, name, score \\ @default_score) do
    scores
    |> Map.put(name,score)
  end

  @spec! remove_player(map, String.t()) :: map
  def remove_player(scores, name) do
    scores
    |> Map.delete(name)
  end

  @spec! reset_score(map, String.t()) :: map
  def reset_score(scores, name) do
    scores
    |> Map.put(name,@default_score)
  end

  @spec update_score(map, String.t(), number) :: map
  def update_score(scores, name, score) do
    scores
    |> Map.update(name,score, fn cur_value -> cur_value + score end)
  end

  @spec get_players(map) :: list
  def get_players(scores) do
    scores
    |> Map.keys
  end
end
