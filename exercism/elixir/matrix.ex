#TODO implement string protocol
defmodule Structure do
  defstruct [:row, :col]
  def new(row) do
    %Structure{row: row}
  end
end


defmodule Matrix do
  # defstruct rows: [], columns: []
  @doc """
  Convert an `input` string, with rows separated by newlines and values
  separated by single spaces, into a `Matrix` struct.
  """
  def create_rows([],matrix,_) do
    matrix
  end


  def create_rows([head | tail], matrix, row) do
    new_matrix = Map.put(matrix, %Structure{row: row} , head)

    create_rows(tail, new_matrix, row+1)
  end

  def create_matrix(list) do
    create_rows(list, %{}, 0)
  end
  def transform(list) do
    Enum.map(list, &String.to_integer(&1))
  end

  # @spec from_string(input :: String.t()) :: %Matrix{}
  def from_string(input) do
    input
    |> String.split("\n")
    |> Enum.map(&String.split(&1))
    |> Enum.map(&transform(&1))
    |> create_matrix
  end

  @doc """
  Write the `matrix` out as a string, with rows separated by newlines and
  values separated by single spaces.
  """
  # @spec to_string(matrix :: %Matrix{}) :: String.t()
  def to_string(matrix) do
    for {_, v} <- matrix do
      v
    end
    |> Enum.map(fn list -> Enum.join(list, " ") end)
    |> Enum.map(fn str -> "#{str}\n" end)
    |> Enum.join("")
    |> String.slice(0..-2)
  end


  # def add_jumpline(acc, [head ])
  @doc """
  Given a `matrix`, return its rows as a list of lists of integers.
  """
  # @spec rows(matrix :: %Matrix{}) :: list(list(integer))
  def rows(matrix) do
    for {_, v} <- matrix do
      v
    end
  end

  @doc """
  Given a `matrix` and `index`, return the row at `index`.
  """
  # @spec row(matrix :: %Matrix{}, index :: integer) :: list(integer)
  def row(matrix, index) do
    Map.get(matrix,%Structure{row: index} )
  end

  @doc """
  Given a `matrix`, return its columns as a list of lists of integers.
  """
  # @spec columns(matrix :: %Matrix{}) :: list(list(integer))
  def columns(matrix) do
    for {_, v} <- matrix do
      v
    end
    |> List.zip
    |> Enum.map(&Tuple.to_list(&1))
  end

  @doc """
  Given a `matrix` and `index`, return the column at `index`.
  """
  # @spec column(matrix :: %Matrix{}, index :: integer) :: list(integer)
  def column(matrix, index) do
    for {_, v} <- matrix do
      v
    end
    |> List.zip
    |> Enum.map(&Tuple.to_list(&1))
    |> Enum.at(index)

  end
end
