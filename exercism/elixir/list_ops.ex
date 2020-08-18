defmodule ListOps do
  # Please don't use any external modules (especially List or Enum) in your
  # implementation. The point of this exercise is to create these basic
  # functions yourself. You may use basic Kernel functions (like `Kernel.+/2`
  # for adding numbers), but please do not use Kernel functions for Lists like
  # `++`, `--`, `hd`, `tl`, `in`, and `length`.

  @spec count(list) :: non_neg_integer
  def count([]) do
   0
  end

  def count([_ | tail]) do
     1 + count(tail)
  end

  @spec reverse(list) :: list
  def reverse(l) do
    reduce(l, [], &([&1 | &2]))
  end


  @spec map(list, (any -> any)) :: list
  def map([head | tail], f) do
    [f.(head) | map(tail, f)]
  end


  @spec map(list, (any -> any)) :: list
  def map([], _f) do
    []
  end

  @spec filter(list, (any -> as_boolean(term))) :: list
  def filter([head | tail], f) do
    cond do
      f.(head) -> [head | filter(tail, f)]
      true -> filter(tail, f)
    end
  end

  def filter([], _f) do
    []
  end



  @type acc :: any
  @spec reduce(list, acc, (any, acc -> acc)) :: acc
  def reduce([head | tail], acc, f) do
   reduce(tail, f.(head,acc), f)
  end

  def reduce([], acc, _f) do
    acc
  end

  @spec append(list, list) :: list
  def append([head_a | tail], b) do
    [head_a | append(tail,b)]
  end

  def append([], b) do
    b
  end

  @spec concat([[any]]) :: [any]
  def concat(ll) do
    ll |> reverse() |> reduce([], &append/2)
  end
end
