defmodule Strain do
  @doc """
  Given a `list` of items and a function `fun`, return the list of items where
  `fun` returns true.

  Do not use `Enum.filter`.
  """
  @spec filter(list, (any -> as_boolean(term))) :: list()

  def filter([], _fucntion) do
    []
  end

  def filter([head | tail], function) do
    cond do
      function.(head) -> [head | filter(tail, function)]
      true -> filter(tail, function)
    end
  end

  def reject([], _fucntion) do
    []
  end

  def reject([head | tail], function) do
    cond do
      !function.(head) -> [head | reject(tail, function)]
      true -> reject(tail, function)
    end
  end

  @spec keep(list :: list(any), fun :: (any -> boolean)) :: list(any)
  def keep(list, fun) do
    filter(list, fun)
  end

  @doc """
  Given a `list` of items and a function `fun`, return the list of items where
  `fun` returns false.

  Do not use `Enum.reject`.
  """
  @spec discard(list :: list(any), fun :: (any -> boolean)) :: list(any)
  def discard(list, fun) do
    reject(list,fun)
  end
end
