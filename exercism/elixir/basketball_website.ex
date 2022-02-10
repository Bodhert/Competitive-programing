defmodule BasketballWebsite do
	@spec extract_from_path(map,String.t()) :: any
  def extract_from_path(data, path) do
    tokens = String.split(path, ".")
    do_extract_from_path(data, tokens)
  end

	@spec do_extract_from_path(map | any, list(String.t()) | nil ) :: any
  defp do_extract_from_path(nil, _), do: nil
  defp do_extract_from_path(data, []), do: data
  defp do_extract_from_path(data, [key | rest]) do
    do_extract_from_path(data[key], rest)
  end

	@spec get_in_path(map,String.t()) :: any
  def get_in_path(data, path) do
    tokens = String.split(path, ".")
    get_in(data, tokens)
  end
end
