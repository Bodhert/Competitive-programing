defmodule NameBadge do
  @spec print(integer() | nil, String.t(), String.t() | nil) :: String.t()
  def print(id, name, department) do
    department = if department, do: String.upcase(department), else: "OWNER"
    prefix = if id, do: "[#{id}] - ", else: ""
    prefix <> "#{name} - #{String.upcase(department)}"
  end

end
